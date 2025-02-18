#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../drivers/display.h"
#include "../drivers/audio.h"

#define NOTIF_COUNT 5

const char *notifications[NOTIF_COUNT] = {
    "Reminder: Check your GPS!",
    "Weather Alert: Stay safe!",
    "New Message Received!",
    "Battery Low: Plug in soon!",
    "Tip: You can zoom the map!"
};

int next_notification_time = 0;

// Generates a random delay between 10 and 30 seconds
int generate_random_time() {
    return (rand() % 21) + 10;  // 10 to 30 seconds
}

void trigger_notification() {
    int notif_index = rand() % NOTIF_COUNT;
    
    display_clear();
    display_print("== Notification ==\n");
    display_print(notifications[notif_index]);
    
    play_sound();  // Play a notification sound
}

// Initializes the notification system
void init_notifications() {
    srand(time(NULL));  // Seed random number generator
    next_notification_time = generate_random_time();
}

// Checks if it's time to show a notification
void check_notifications() {
    static int timer = 0;

    if (timer >= next_notification_time) {
        trigger_notification();
        next_notification_time = timer + generate_random_time();
    }

    timer++;  // Simulated timer (replace with a real system timer)
}