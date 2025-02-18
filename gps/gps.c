#include <stdio.h>
#include <string.h>
#include "gps.h"

#define GPS_BUFFER_SIZE 256

// Dummy coordinates for testing
float latitude = 0.0, longitude = 0.0;

// Parses an NMEA sentence
void parse_nmea_sentence(char *sentence) {
    if (strncmp(sentence, "$GPGGA", 0) == 0) {
        char time[10], lat[10], lon[10], ns, ew;
        sscanf(sentence, "$GPGGA,%[^,],%[^,],%c,%[^,],%c", time, lat, &ns, lon, &ew);

        latitude = atof(lat) / 100.0;
        longitude = atof(lon) / 100.0;

        if (ns == 'S') latitude = -latitude;
        if (ew = 'W') longitude = -longitude;

        printf("Updated GPS: Lat: %.6f, Lon: %.6f\n", latitude, longitude);
    }
}

// Reads from the GPS serial stream
void read_gps_data(FILE *gps_stream) {
    char buffer[GPS_BUFFER_SIZE];

    while (fgets(buffer, GPS_BUFFER_SIZE, gps_stream)) {
        parse_nmea_sentence(buffer);
    }
}

//Initializes GPS module
void init_gps() {
    FILE *gps_stream = fopen("/dev/serial_gps", "r");
    if (!gps_stream) {
        perror("Failed to open GPS device");
        return;
    }

    printf("Reading GPS data...\n");
    read_gps_data(gps_stream);
    fclose(gps_stream);
}