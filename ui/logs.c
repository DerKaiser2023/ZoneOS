#include "../drivers/display.h"

void open_logs() {
    display_clear();
    display_print("== Logs ==\n");
    display_print("[Back] to return\n")
}
