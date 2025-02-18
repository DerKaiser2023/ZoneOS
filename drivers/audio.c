#include "audio.h"

#define AUDIO_REGISTER 0xB0000000  // Replace with actual hardware address

void play_beep() {
    volatile unsigned int *audio = (volatile unsigned int *)AUDIO_REGISTER;
    for (int i = 0; i < 100000; i++) {
        *audio = (i % 100) < 50 ? 1 : 0;  // Simple square wave
    }
}

void play_sound() {
    // TODO: Implement real sound output (use a buzzer or speaker)
    printf("[BEEP] Notification sound played.\n");
}