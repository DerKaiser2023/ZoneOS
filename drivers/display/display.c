#include "display.h"

#define FRAMEBUFFER_ADDR 0xA0000000  // Example framebuffer address

volatile unsigned int *fb = (volatile unsigned int *)FRAMEBUFFER_ADDR;

void display_init() {
    // Hardware-specific display init code here
}

void display_clear() {
    for (int i = 0; i < (320 * 240); i++) {
        fb[i] = 0x000000;  // Black screen
    }
}

void display_print(const char *msg) {
    // Simple text rendering (placeholder)
}
