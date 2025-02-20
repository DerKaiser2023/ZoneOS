#include <stdio.h>
#include <string.h>
#include "display.h"
#include "boot_image.h"

#define FRAMEBUFFER_ADDR 0xA0000000  // Example framebuffer address

volatile unsigned int *fb = (volatile unsigned int *)FRAMEBUFFER_ADDR;

// Initialize the display hardware
void display_init() {
    // TODO: Implement real hardware initialization
    printf("[DISPLAY] Initialized\n");
}

// Clear the entire screen
void display_clear() {
    for (int i = 0; i < (320 * 240); i++) {
        fb[i] = 0x000000;  // Black screen
    }
}

// Draw a single pixel at (x, y)
void draw_pixel(int x, int y, unsigned int color) {
    if (x >= 0 && x < 320 && y >= 0 && y < 240) { 
        fb[y * 320 + x] = color;
    }
}

// Improved text rendering (simulated for now)
void draw_text(int x, int y, const char *msg) {
    printf("[DISPLAY] %s at (%d, %d)\n", msg, x, y);
}

// Print text to the screen at a new line
void display_print(const char *msg) {
    static int line = 0;
    int y_offset = line * 10;  // Adjust line spacing

    draw_text(10, y_offset, msg);
    line++;
}

// Display an image from raw pixel data
void display_draw_image(const unsigned int *image_data) {
    for (int i = 0; i < (320 * 240); i++) {
        fb[i] = image_data[i]; // Copy pixel data to framebuffer
    }
}

// Draw a progress bar at the bottom of the screen
void draw_progress_bar(int percent) {
    int bar_x = 20, bar_y = 200, bar_width = 280, bar_height = 20;
    int filled_width = (percent * bar_width) / 100;

    // Draw the empty progress bar
    for (int y = 0; y < bar_height; y++) {
        for (int x = 0; x < bar_width; x++) {
            draw_pixel(bar_x + x, bar_y + y, (x < filled_width) ? 0x00FF00 : 0x444444);
        }
    }

    // Display percentage text
    char percent_text[10];
    sprintf(percent_text, "%d%%", percent);
    draw_text(bar_x + bar_width / 2 - 10, bar_y - 10, percent_text);
}