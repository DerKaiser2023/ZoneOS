#include "../drivers/display.h"

void open_map() {
    display_clear();
    display_print("== Map ==\n");
    display_print("[Back] to return\n")
}
