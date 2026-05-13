#include <stdio.h>
#include <unistd.h>

void greenState();
void yellowState();
void redState();

void (*currentState)();

int greenDuration = 3;
int yellowDuration = 2;
int redDuration = 4;

void greenState() {
    printf("GREEN light - Go!\n");
    sleep(greenDuration);
    currentState = yellowState;
}

void yellowState() {
    printf("YELLOW light - Prepare to stop!\n");
    sleep(yellowDuration);
    currentState = redState;
}

void redState() {
    printf("RED light - Stop!\n");
    sleep(redDuration);
    currentState = greenState;
}

int main() {
    currentState = greenState;

    for (int i = 0; i < 10; i++) {
        currentState();
    }

    printf("Traffic light simulation finished.\n");
    return 0;
}

