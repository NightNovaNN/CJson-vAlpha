#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cjson.h"

// find "key": "value"
static char* find_key(const char *json, const char *key) {
    static char out[256];
    out[0] = 0;

    char pattern[256];
    sprintf(pattern, "\"%s\"", key);

    char *pos = strstr(json, pattern);
    if (!pos) return NULL;

    pos = strchr(pos + strlen(pattern), ':');
    if (!pos) return NULL;

    pos++;
    while (*pos == ' ' || *pos == '\n' || *pos == '\t') pos++;

    return pos;
}

char* json_get_string(const char *json, const char *key) {
    static char value[256];
    value[0] = 0;

    char *pos = find_key(json, key);
    if (!pos || *pos != '"') return NULL;

    pos++;
    char *end = strchr(pos, '"');
    if (!end) return NULL;

    int len = end - pos;
    strncpy(value, pos, len);
    value[len] = 0;

    return value;
}

int json_get_int(const char *json, const char *key) {
    char *pos = find_key(json, key);
    if (!pos) return 0;

    return atoi(pos);
}

int json_get_bool(const char *json, const char *key) {
    char *pos = find_key(json, key);
    if (!pos) return 0;

    if (strncmp(pos, "true", 4) == 0) return 1;
    if (strncmp(pos, "false", 5) == 0) return 0;

    return 0;
}
