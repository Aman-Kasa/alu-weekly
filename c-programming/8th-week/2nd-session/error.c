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
    struct Device *d = NULL;

    d->serialNumber = 5555;
    strcpy(d->model, "Sensor-X");
    d->batteryLevel = 76.5;

    printf("Device Serial: %d\n", d->serialNumber);
    printf("Device Model: %s\n", d->model);
    printf("Battery Level: %.1f%%\n", d->batteryLevel);

    return 0;
}
