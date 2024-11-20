#include <stdio.h>
#include <stdlib.h>
#include "display.h"


int main() {
    if (open_display()) {
	return 1;
}
    int hours, minutes, seconds;

    while (1) {
        if (scanf("%d:%d:%d",&hours, &minutes, &seconds) != 3) {
            break;
        }
        // Display the time on the LED matrix
        display_time(hours, minutes, seconds);
    }
    close_display();
    return 0;
}

