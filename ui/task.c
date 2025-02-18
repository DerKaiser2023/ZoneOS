#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../drivers/display.h"
#include "../drivers/audio.h"
#include "../gps/gps.h"

#define TASK_COUNT 3

typedef struct {
    const char *name;
    float target_lat;
    float target_lon;
    int accepted;
    int completed;
} Task;

Task task_list[TASK_COUNT] = {
    {"Find Lost Documents", 34.0522, -118.2437, 0, 0},  // Example coordinates
    {"Eliminate Target", 40.7128, -74.0060, 0, 0},  
    {"Retrieve Package", 51.5074, -0.1278, 0, 0}  
};

Task *current_task = NULL;
float start_lat, start_lon;  // Save user's starting position

void display_task_menu() {
    display_clear();
    display_print("== Available Tasks ==\n");

    for (int i = 0; i < TASK_COUNT; i++) {
        printf("[%d] %s\n", i + 1, task_list[i].name);
    }

    display_print("\nPress a number to accept task, or [0] to cancel.");
}

// User selects a task
void accept_task(int task_index) {
    if (task_index < 0 || task_index >= TASK_COUNT) return;

    current_task = &task_list[task_index];
    current_task->accepted = 1;
    current_task->completed = 0;

    // Save current position as starting point
    start_lat = latitude;
    start_lon = longitude;

    display_clear();
    display_print("Task Accepted: ");
    display_print(current_task->name);
    display_print("\nHead to the marked location.\n");

    play_sound();
}

// Checks if the player has reached the task location
void update_task() {
    if (!current_task || !current_task->accepted || current_task->completed) return;

    float dist_to_target = (latitude - current_task->target_lat) * (latitude - current_task->target_lat) +
                           (longitude - current_task->target_lon) * (longitude - current_task->target_lon);

    if (dist_to_target < 0.0001) {  // Reached task location
        display_print("Task Objective Completed!\n");
        play_sound();

        // Update task to return to starting point
        current_task->target_lat = start_lat;
        current_task->target_lon = start_lon;
        display_print("Return to start to complete the task.\n");
    }

    float dist_to_start = (latitude - start_lat) * (latitude - start_lat) +
                          (longitude - start_lon) * (longitude - start_lon);

    if (dist_to_start < 0.0001 && current_task->target_lat == start_lat) {  
        display_print("Task Fully Completed!\n");
        current_task->completed = 1;
        play_sound();
    }
}

// Initializes task system
void init_tasks() {
    srand(time(NULL));  // Random seed
    display_task_menu();
}