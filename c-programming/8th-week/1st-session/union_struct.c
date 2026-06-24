#include <stdio.h>

/* Define union */
union SensorData
{
    int temperature;
    float humidity;
};

/* Define equivalent struct */
struct SensorStruct
{
    int temperature;
    float humidity;
};

int main(void)
{
    union SensorData udata;
    struct SensorStruct sdata;

    /* --- Union Example --- */
    printf("Union Example:\n");
    printf("Enter value for temperature: ");
    scanf("%d", &udata.temperature);

   printf("Enter value for humidity: ");
   scanf("%f", &udata.humidity);

    /* Only the last assigned member is valid */
    printf("\nStored values in union:\n");
    printf("Temperature: %d\n", udata.temperature); // likely overwritten
   // printf("Humidity: %.2f\n", udata.humidity);     // last input is valid

    printf("Size of union: %zu bytes\n\n", sizeof(udata));

    /* --- Struct Example --- */
    printf("Struct Example:\n");
    printf("Enter value for temperature: ");
    scanf("%d", &sdata.temperature);

    printf("Enter value for humidity: ");
    scanf("%f", &sdata.humidity);

    /* All members are valid in struct */
    printf("\nStored values in struct:\n");
    printf("Temperature: %d\n", sdata.temperature);
    printf("Humidity: %.2f\n", sdata.humidity);

    printf("Size of struct: %zu bytes\n", sizeof(sdata));

    return 0;
}

