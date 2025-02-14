#include "drivers/display/display.h"

void kernel_main() {
    display_init();
    display_clear();
    display_print("ZoneOS Is Booting...\n");

    while (1) {
        // Main loop for the OS
    }
}
