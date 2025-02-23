#include "fat32.h"
#include <stdio.h>
#include <string.h>

// Simulated FAT32 storage
FAT32_File fake_file = { "SOUND.WAV", 1024, 0};

int fat32_init() {
    printf("[FAT32] Initialized FAT32 file system\n");
    return 0;
}

FAT32_File *fat32_open(const char *filename) {
    if (strcmp(filename, "SOUND.WAV") == 0) {
        printf("[FAT32] Opening %s\n", filename);
        return &fake_file;
    }
    printf("[FAT32] File not found: %s\n", filename);
    return NULL;
}

int fat32_read(FAT32_File *file, void *buffer, int size) {
    printf("[FAT32] Reading %d bytes from %s\n", size, file->name);
    memset(buffer, 0xAA, size); // Simulated audio data
    return size;
}

void fat32_close(FAT32_File *file) {
    printf("[FAT32] Closing file %s\n", file->name);
}