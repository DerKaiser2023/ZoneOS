#include "display.h"
#include "input.h"

void draw_menu() {
    display_clear();
    display_print("=== ZoneOS PDA ===\n");
    display_print("[1] Test\n");
    display_print("[2] Map\n");
    display_print("[3] Logs\n");
}

void handle_menu_input() {
    int key = get_key_input();
    if (key == 1) {
        open_inventory();
    } else if (key == 2) {
        open_map();
    } else if (key == 3) {
        open_logs();
    }
}
