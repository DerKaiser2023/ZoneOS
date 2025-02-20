#include <stdio.h>
#include "../drivers/display.h"
#include "../drivers/input.h"
#include "../drivers/storage.h"

void draw_progress_bar(int percent) {
    display_clear();
    display_print("== ZoneOS Setup ==\n");
    display_print("Installing... Please wait.\n");

    int bar_length = 20;  // Total width of the progress bar
    int filled = (percent * bar_length) / 100;

    display_print("[");
    for (int i = 0; i < filled; i++) display_print("=");
    for (int i = filled; i < bar_length; i++) display_print(" ");
    display_print("] ");

    char percent_text[10];
    sprintf(percent_text, "%d%%\n", percent);
    display_print(percent_text);
}

void run_setup() {
    display_clear();
    display_print("== ZoneOS Setup ==\n");
    display_print("[1] Install ZoneOS\n");
    display_print("[2] Exit to Bootloader\n");

    int choice = get_user_input();  // Reads user button input

    if (choice == 1) {
        display_clear();
        display_print("Starting Installation...\n");

        // Step 1: Format Storage
        draw_progress_bar(10);
        format_storage();
        
        // Step 2: Copy OS Files
        draw_progress_bar(50);
        copy_os_files();
        
        // Step 3: Install Bootloader
        draw_progress_bar(80);
        install_bootloader();
        
        // Step 4: Finish
        draw_progress_bar(100);
        display_print("\nInstallation Complete! Rebooting...\n");
        reboot_device();
    } else {
        display_print("Exiting to Bootloader...\n");
    }
}