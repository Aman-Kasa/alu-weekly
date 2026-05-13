#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Device
{
    int serialNumber;
    char model[30];
    float batteryLevel;
};

int main()
{
    // Allocate memory for the Device struct
    struct Device *d = malloc(sizeof(struct Device));
    if (!d) {  // Check if allocation succeeded
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the fields
    d->serialNumber = 5555;
    strcpy(d->model, "Sensor-X");
    d->batteryLevel = 76.5;

    // Print the device info
    printf("Device Serial: %d\n", d->serialNumber);
    printf("Device Model: %s\n", d->model);
    printf("Battery Level: %.1f%%\n", d->batteryLevel);

    // Free the allocated memory
    free(d);

    return 0;
}

