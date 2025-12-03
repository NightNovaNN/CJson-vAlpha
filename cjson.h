#ifndef CJSON_H
#define CJSON_H

char* json_get_string(const char *json, const char *key);
int   json_get_int(const char *json, const char *key);
int   json_get_bool(const char *json, const char *key);

#endif
