#include "sense.h"
#include <stdio.h>
#include "display.h"

pi_framebuffer_t *dev= NULL;

int open_display(void) {
    dev= getFrameBuffer();
    if (dev == NULL) {
	return 1;
	}
    return 0;
}

void display_colons(void) {
    for (int i = 1; i < 6; i++) {
        for (int j = 2; j < 7; j++) {
            // Leave the middle column empty for the colon
            if (i == 3 || j == 4) {
                continue;
            }
            dev->bitmap->pixel[i][j] = getColor(100, 100, 100); 
        }
    }
}

void display_time(int hours, int minutes, int seconds) {
    display_colons();
    display_hours(hours);
    display_minutes(minutes);
    display_seconds(seconds);
}

void display_hours(int hours) {
    uint16_t blue = getColor(0, 0, 150);
    for (int i = 5; i >= 0; i--) {
        // Check if the bit is set and display accordingly
        dev->bitmap->pixel[6][7-i] = (hours & (1 << i)) ? blue : getColor(0, 0, 0);
    }
}

void display_minutes(int minutes) {
    uint16_t green = getColor(0, 150, 0);
    for (int i = 5; i >= 0; i--) {
        dev->bitmap->pixel[3][7-i] = (minutes & (1 << i)) ? green : getColor(0, 0, 0);
    }
}

void display_seconds(int seconds) {
    uint16_t red = getColor(150, 0, 0);
    for (int i = 5; i >= 0; i--) {
        dev->bitmap->pixel[0][7-i] = (seconds & (1 << i)) ? red : getColor(0, 0, 0);
    }
}
void close_display(void) {
    clearFrameBuffer(dev, getColor(0,0,0));
    freeFrameBuffer(dev);
}
