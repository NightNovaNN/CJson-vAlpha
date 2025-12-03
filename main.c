#include <stdio.h>
#include "cjson.h"

int main() {
    //test example
    const char *json =
        "{"
        "  \"name\": \"Cryo\","
        "  \"version\": 7,"
        "  \"cool\": true"
        "}";

    printf("Name: %s\n", json_get_string(json, "name"));
    printf("Version: %d\n", json_get_int(json, "version"));
    printf("Cool: %d\n", json_get_bool(json, "cool"));

    return 0;
}
