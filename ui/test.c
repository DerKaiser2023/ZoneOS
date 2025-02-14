#include "../drivers/display.h"

void open_test() {
    display_clear();
    display_print("== Test ==\n");
    display_print("[Back] to return\n");
}
