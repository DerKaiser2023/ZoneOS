#include <stdio.h>
#include "display.h"
#include "boot_image.h"

void draw_pixel(int x, int y, char pixel) {
    printf("Drawing '%c' at (%d, %d)\n", pixel, x, y);
}

#define FRAMEBUFFER_ADDR 0xA0000000  // Example framebuffer address

volatile unsigned int *fb = (volatile unsigned int *)FRAMEBUFFER_ADDR;

void display_init() {
    // Hardware-specific display initialization
}

void display_clear() {
    for (int i = 0; i < (320 * 240); i++) {
        fb[i] = 0x000000;  // Black screen
    }
}

void display_print(const char *msg) {
    // Placeholder text rendering
}

void display_draw_image(const unsigned int *image_data) {
    for (int i = 0; i < (320 * 240); i++) {
        fb[i] = image_data[i]; // Copy pixel data to framebuffer
    }
}
