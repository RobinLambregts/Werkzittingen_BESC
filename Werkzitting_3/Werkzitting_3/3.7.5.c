#define

#include <stdio.h>
#include <string.h>

void oefening375(char* zin, int* arr[9]) {
    const char* s = " .,";
    char* token;
    /* Get first token*/
    token = strtok(zin, s);

    while (token != NULL) {
        printf(" %s\n", token);

        int lengte = strlen(token);

        if (lengte >= 1 && lengte <= 9) {
            arr[lengte - 1]++;
        }
        else if (lengte >= 10) {
            arr[8]++;
        }

        token = strtok(NULL, s);
    }
}