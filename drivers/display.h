#ifndef DISPLAY_H
#define DISPLAY_H

void display_init();
void display_clear();
void display_print(const char *msg);
void display_draw_image(const unsigned int *image_data); // New function

#endif
