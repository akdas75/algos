
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned char bool;

int main () {

    char str[] = "abcbaj";

    int len = strlen (str);

    bool isPalinDrone = true;

    for (int i = 0; i<len; i++) {

        if (str[i] != str[len - 1 - i]) {
            isPalinDrone = false;
            break;
        }
    }

    printf ("isPalinDrone %d \n",isPalinDrone);

}