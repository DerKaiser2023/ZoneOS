#include <stdio.h>
#include "../drivers/display.h"
#include "../drivers/input.h"
#include "../drivers/storage.h"

void run_setup() {
    display_clear();
    display_print("== ZoneOS Setup ==\n");
    display_print("[1] Install ZoneOS\n");
    display_print("[2] Exit to Bootloader\n");

    int choice = get_user_input(); // Reads user button input

    if (choice == 1) {
        display_clear();
        display_print("Installing ZoneOS...\n");

        format_storage(); // Format the internal flash storage
        copy_os_files(); // Copy kernel & system files
        install_bootloader(); // Flash the bootloader

        display_print("Installation Complete! Rebooting...\n");
        reboot_device();
    } else {
        display_print("Exiting to Bootloader...\n");
    }
}