#include <stdio.h>

int main(void) 
{
    int temperatur[2][3] = 
    {
        {21, 22, 20},
        {19, 18, 20}
    };
    for (int sensor = 0; sensor < 3; sensor++) 
    {
        for (int dag = 0; dag < 2; dag++)
        {
            printf("%d ", temperatur[sensor][dag]);
        }
        printf("\n");
    }

    for (int i = 0; i < 6; i++)
    {
        printf("Temperatur box: %d has value %d\n", i+1, temperatur[0][i]);
    }

    printf("temperatur at %p\n", (void*)temperatur);
    printf("Size of temperatur %lld\n", sizeof(temperatur));
    printf("Get second element on second row: %d\n", temperatur[1][1]);
    return 0;
}