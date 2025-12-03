# CJson-vAlpha
MVP small minimal version of a data handler in C for JSON  
Used for JSON Data Handling in C, A Polished version releasing soon  

## Example
```c
#include <stdio.h>
#include "microjson.h"

int main() {
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
```
