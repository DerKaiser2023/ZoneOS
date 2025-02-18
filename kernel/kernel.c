#include "drivers/display.h"
#include "gps/gps.h"
#include "ui/map.h"
#include "ui/notifications.h"
#include "ui/task.h"

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