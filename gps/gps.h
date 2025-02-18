#ifndef GPS_H
#define GPS_H

extern float latitude, longitude;

void init_gps();
void read_gps_data(FILE *gps_stream);
void parse_nmea_sentence(char *sentence);

#endif