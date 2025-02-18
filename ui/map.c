#include <stdio.h>
#include "../drivers/display.h"
#include "gps.h"

#define MAP_WIDTH  240  // Adjust to your device screen resolution
#define MAP_HEIGHT 320
#define GPS_MARKER 'X'

// Dummy function to load map
void load_map() {
    printf("Loading map...\n");
}

// Renders GPS location on the map
void render_gps_location() {
    int x = (int)((longitude + 180) / 360 * MAP_WIDTH);
    int y = (int)((90 - latitude) / 180 * MAP_HEIGHT);

    draw_pixel(x, y, GPS_MARKER);
    printf("GPS Marker drawn at (%d, %d)\n", x, y);
}

// Main function to update map
void update_map() {
    load_map();
    render_gps_location();
}

void open_map() {
    display_clear();
    display_print("== Map ==\n");
    display_print("[Back] to return\n");
}