#include "audio.h"
#include "../fs/vfs.h"
#include <stdio.h>
#include <stdint.h>

#define AUDIO_BUFFER_SIZE 4096  // Buffer for audio playback

void play_sound() {
    printf("[AUDIO] Beep sound played.\n");
}

void play_wav(const char *filename) {
    VFS_File *wav_file = vfs_open(filename, VFS_READ);
    if (!wav_file) {
        printf("[AUDIO] Error: Cannot open WAV file %s\n", filename);
        return;
    }

    // Read WAV header
    uint8_t header[44];
    vfs_read(wav_file, header, 44);  

    uint8_t buffer[AUDIO_BUFFER_SIZE];
    int bytes_read;
    
    while ((bytes_read = vfs_read(wav_file, buffer, AUDIO_BUFFER_SIZE)) > 0) {
        // TODO: Send audio data to the WM8750 codec for playback
        printf("[AUDIO] Playing chunk of %d bytes\n", bytes_read);
    }

    vfs_close(wav_file);
    printf("[AUDIO] Finished playing %s\n", filename);
}