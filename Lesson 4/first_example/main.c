#include <stdio.h>

#define MAX_ARRAY_SIZE_INT 10

void loop_thru_int_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Sensor index %d has int value %d\n", i, arr[i]);
    }
}

int main(void) 
{   
    // int sensorer[MAX_ARRAY_SIZE_INT] = {21, 19, 23, 18, 22};
    int sensorer[MAX_ARRAY_SIZE_INT];
    printf("sensorer is located at %p\n", (void*)sensorer);
    printf("sensorer first value is at %p\n", (void*)&sensorer[0]);
    printf("sensorer second value is at %p\n", (void*)&sensorer[1]);
    printf("Forsta vardet: %d\n", sensorer[0]);
    printf("Tredje vardet: %d\n", sensorer[2]);
    printf("Sjette vardet: %d\n", sensorer[5]);
    printf("Sista vardet: %d\n", sensorer[9]);
    printf("Vardet efter Sista vardet: %d\n", sensorer[MAX_ARRAY_SIZE_INT + 1]); // BAD
    printf("Bad value, lets fix that!\n");
    sensorer[MAX_ARRAY_SIZE_INT + 1] = 0;
    printf("Vardet efter Sista vardet: %d\n", sensorer[MAX_ARRAY_SIZE_INT + 1]); // BAD
    // float temperatur[]; Dont do this
    printf("Storleken pa sensorer ar %zu\n", sizeof(sensorer));
    printf("Antal element i sensorer ar %lld\n", sizeof(sensorer)/sizeof(sensorer[0]));

    loop_thru_int_array(sensorer, MAX_ARRAY_SIZE_INT);   
    // loop_thru_int_array(&sensorer[0], MAX_ARRAY_SIZE_INT);   
    // for(int i = 0; i < 2 * MAX_ARRAY_SIZE_INT; i++)
    // {
    //     printf("Sensor index %d has int value %d\n", i, sensorer[i]);
    // }

    return 0;
}