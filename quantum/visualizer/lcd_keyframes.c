/* Copyright 2017 Fred Sundvik
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "lcd_keyframes.h"
#include <string.h>
#include <math.h>
#include "action_util.h"
#include "led.h"
#include "resources/resources.h"

bool lcd_keyframe_display_layer_text(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
    gdispClear(White);
    gdispDrawString(0, 10, state->layer_text, state->font_dejavusansbold12, Black);
    return false;
}

static void format_layer_bitmap_string(uint16_t default_layer, uint16_t layer, char* buffer) {
    for (int i=0; i<16;i++)
    {
        uint32_t mask = (1u << i);
        if (default_layer & mask) {
            if (layer & mask) {
                *buffer = 'B';
            } else {
                *buffer = 'D';
            }
        } else if (layer & mask) {
            *buffer = '1';
        } else {
            *buffer = '0';
        }
        ++buffer;

        if (i==3 || i==7 || i==11) {
            *buffer = ' ';
            ++buffer;
        }
    }
    *buffer = 0;
}

bool lcd_keyframe_display_layer_bitmap(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
    const char* layer_help = "1=On D=Default B=Both";
    char layer_buffer[16 + 4]; // 3 spaces and one null terminator
    gdispClear(White);
    gdispDrawString(0, 0, layer_help, state->font_fixed5x8, Black);
    format_layer_bitmap_string(state->status.default_layer, state->status.layer, layer_buffer);
    gdispDrawString(0, 10, layer_buffer, state->font_fixed5x8, Black);
    format_layer_bitmap_string(state->status.default_layer >> 16, state->status.layer >> 16, layer_buffer);
    gdispDrawString(0, 20, layer_buffer, state->font_fixed5x8, Black);
    return false;
}

static void format_mods_bitmap_string(uint8_t mods, char* buffer) {
    *buffer = ' ';
    ++buffer;

    for (int i = 0; i<8; i++)
    {
        uint32_t mask = (1u << i);
        if (mods & mask) {
            *buffer = '1';
        } else {
            *buffer = '0';
        }
        ++buffer;

        if (i==3) {
            *buffer = ' ';
            ++buffer;
        }
    }
    *buffer = 0;
}

bool lcd_keyframe_display_mods_bitmap(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;

    const char* title = "Modifier states";
    const char* mods_header = " CSAG CSAG ";
    char status_buffer[12];

    gdispClear(White);
    gdispDrawString(0, 0, title, state->font_fixed5x8, Black);
    gdispDrawString(0, 10, mods_header, state->font_fixed5x8, Black);
    format_mods_bitmap_string(state->status.mods, status_buffer);
    gdispDrawString(0, 20, status_buffer, state->font_fixed5x8, Black);

    return false;
}

#define LED_STATE_STRING_SIZE sizeof("NUM CAPS SCRL COMP KANA")

static void get_led_state_string(char* output, visualizer_state_t* state) {
    uint8_t pos = 0;

    if (state->status.leds & (1u << USB_LED_NUM_LOCK)) {
        memcpy(output + pos, "NUM ", 4);
        pos += 4;
    }
    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        memcpy(output + pos, "CAPS ", 5);
        pos += 5;
    }
    if (state->status.leds & (1u << USB_LED_SCROLL_LOCK)) {
        memcpy(output + pos, "SCRL ", 5);
        pos += 5;
    }
    if (state->status.leds & (1u << USB_LED_COMPOSE)) {
        memcpy(output + pos, "COMP ", 5);
        pos += 5;
    }
    if (state->status.leds & (1u << USB_LED_KANA)) {
        memcpy(output + pos, "KANA", 4);
        pos += 4;
    }
    output[pos] = 0;
}

bool lcd_keyframe_display_led_states(keyframe_animation_t* animation, visualizer_state_t* state)
{
    (void)animation;
    char output[LED_STATE_STRING_SIZE];
    get_led_state_string(output, state);
    gdispClear(White);
    gdispDrawString(0, 10, output, state->font_dejavusansbold12, Black);
    return false;
}

bool lcd_keyframe_display_layer_and_led_states(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
    gdispClear(White);
    uint8_t y = 10;
    if (state->status.leds) {
        char output[LED_STATE_STRING_SIZE];
        get_led_state_string(output, state);
        gdispDrawString(0, 1, output, state->font_dejavusansbold12, Black);
        y = 17;
    }
    gdispDrawString(0, y, state->layer_text, state->font_dejavusansbold12, Black);
    return false;
}

bool lcd_keyframe_draw_logo(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)state;
    (void)animation;
    // Read the uGFX documentation for information how to use the displays
    // http://wiki.ugfx.org/index.php/Main_Page
    gdispClear(White);

    // You can use static variables for things that can't be found in the animation
    // or state structs, here we use the image

    //gdispGBlitArea is a tricky function to use since it supports blitting part of the image
    // if you have full screen image, then just use LCD_WIDTH and LCD_HEIGHT for both source and target dimensions
    gdispGBlitArea(GDISP, 0, 0, LCD_WIDTH, LCD_HEIGHT, 0, 0, LCD_WIDTH, (pixel_t*)resource_lcd_logo);

    return false;
}


bool lcd_keyframe_disable(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
    (void)state;
    gdispSetPowerMode(powerOff);
    return false;
}

bool lcd_keyframe_enable(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
    (void)state;
    gdispSetPowerMode(powerOn);
    return false;
}

static void format_double_bitmap_string(double n, char* buffer) {
	char *save = buffer; // Save pointer to the beginning of the string
	bool neg = false;
	if (n < 0) { // If number is negative, make it positive
		n *= -1;
		neg = true;
	}

	uint64_t i = roundf(n * 10000); // Round to a maximum of 4 decimal places
	uint64_t f = i % 10000; // Save frraction to separate variable
	bool frac = false; // Save if the fraction was 0
	if (f != 0)
		frac = true;
	i /= 10000;

	while (( (f % 10) == 0) && frac) { // Skip trailing zeros in fraction
		f /= 10;
	}
	while (f != 0) { // Loop through fraction and add digits to the buffer
		*buffer = (f % 10) + '0';
		++buffer;
		f /= 10;
	}
	if (frac && i == 0) { // Add '.0' if the integer is 0
		*buffer = '.';
		++buffer;
		*buffer = '0';
		++buffer;
	} else if (frac) { // Add decimal point if the integer is not 0
		*buffer = '.';
		++buffer;
	} else if (i == 0) { // If the fraction and integer are 0 write a 0 to the buffer and return
		*buffer = '0';
		++buffer;
		*buffer = 0;
		return;
	}
	while (i != 0) { // Loop through the integer and add digits to the buffer
		*buffer = (i % 10) + '0';
		++buffer;
		i /= 10;
	}
	if (neg) { // If the number was negative add a '-'
		*buffer = '-';
		++buffer;
	}
	*buffer = 0;
	--buffer;

	while (save < buffer) { // Reverse number string
		char tmp = *buffer;
		*buffer = *save;
		*save = tmp;
		--buffer;
		++save;
	}
}

bool lcd_keyframe_display_rpn_stack(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
	char stack_buffer[32] = { 0 };
    gdispClear(White);

	format_double_bitmap_string(state->status.user_data.stack[0], stack_buffer);
    gdispDrawString(0, 2, "Z: ", state->font_fixed5x8, Black);
	gdispDrawString(15, 2, stack_buffer, state->font_fixed5x8, Black);

	format_double_bitmap_string(state->status.user_data.stack[1], stack_buffer);
    gdispDrawString(0, 12, "Y: ", state->font_fixed5x8, Black);
	gdispDrawString(15, 12, stack_buffer, state->font_fixed5x8, Black);

	format_double_bitmap_string(state->status.user_data.buffer, stack_buffer);
    gdispDrawString(0, 22, "X: ", state->font_fixed5x8, Black);
	gdispDrawString(15, 22, stack_buffer, state->font_fixed5x8, Black);
    return false;
}

