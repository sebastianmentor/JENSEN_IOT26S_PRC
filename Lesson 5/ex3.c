#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NR_OF_INT 5

void sum_array_of_int(int *arr, int len, int *sum);

int main(void) 
{   
    int arr[MAX_NR_OF_INT] = {1,2,3,4,5};
    int *ptr = arr;
    printf("ptr decay to %d\n", *ptr); // *(ptr + 0)
    printf("arr first value is %d\n", arr[0]);
    printf("ptr second value is %d\n", *(ptr + 1));
    printf("arr first value is %d\n", arr[1]);

    if ((ptr+1) == &arr[1])
    {
        printf("(ptr+1) == &arr[1] is true!!!");
    }

    printf("Dont do this stupid thing *(p + 5) = %d\n", *(ptr + 5));
    
    int main_local_sum = 0;
    sum_array_of_int(arr, MAX_NR_OF_INT, &main_local_sum);
    printf("Total sum is %d\n", main_local_sum);


    return 0;
}

void sum_array_of_int(int *arr, int len, int *sum)
{
    int local_sum = 0;
    for (int i = 0; i < len; i++)
    {
        local_sum += *(arr + i);
    }

    *sum = local_sum;
}

