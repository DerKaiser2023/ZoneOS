#ifndef FAT32_H
#define FAT32_H

#include <stdint.h>

typedef struct {
    char name[11]; // 8.3 filename
    uint32_t size; // File size
    uint32_t cluster; // First cluster
} FAT32_File;

int fat32_init(); // Initializes FAT32 system
FAT32_File *fat32_open(const char *filename);
int fat32_read(FAT32_File *file, void *buffer, int size);
void fat32_close(FAT32_File *file);

#endif