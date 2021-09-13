#ifndef SPO_LAB3_UTILS_H
#define SPO_LAB3_UTILS_H

#include <stdbool.h>

char *ltrim(char *str, const char *sep);
char *rtrim(char *str, const char *sep);
char *trim(char *str);
char *trim1(char *str, const char *sep);
int seek_substring_KMP(char *source, char *find);

bool isValidIpAddress(char *ipAddress);

#endif //SPO_LAB3_UTILS_H
