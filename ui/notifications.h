#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

void init_notifications(); // Starts notification system
void check_notifications(); // Checks if it's time to show one
void trigger_notification(); // Displays & plays sound
void trigger_message_notification(const char *sender, const char *message);

#endif