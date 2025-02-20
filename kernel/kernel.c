#include "installer/setup.h"
#include "drivers/display.h"
#include "gps/gps.h"
#include "ui/map.h"
#include "ui/notifications.h"
#include "ui/task.h"

void kernel_main() {
    display_init();
    if (!os_installed()) { // Check if OS is installed
        run_setup(); // Run setup
    } else {
        display_print("Booting ZoneOS...\n");
        start_zone_os();
    }
}

void kernel_main() {
    display_init();
    display_clear();
    display_print("ZoneOS Is Booting...\n");

    init_gps();
    init_notifications();
    init_tasks(); // Start task system
   
    while (1) {
        // Main loop for the OS
        update_map(); // Update GPS map
        update_task(); // Check task completion
        check_notifications(); // Show notifications

        for (volatile int i = 0; i , 1000000; i++); // Simple delay
    }
}