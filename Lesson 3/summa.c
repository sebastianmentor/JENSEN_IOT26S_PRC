#include <stdio.h>

void print_sum_of_two(int a, int b)
{
    printf("The sum of %d and %d is %d\n", a, b, a+b);
}

void print_sum_of_three(int a, int c, int b)
{
    printf("The sum of %d, %d and %d is %d\n",a, b, c, a+b+c);
}

float sum_of_two_float(float x, float y)
{
    return x + y;
}
float sum_of_three_float(float x, float y, float z)
{
    // return sum_of_two_float(sum_of_two_float(x, y), z);
    return x + y + z;
}

void print_sum_of_two_floats_n_times(float x, float y, int number_of_times)
{
    for(int i = 0; i<number_of_times; i++)
    {
        printf("The sum of %f and %f is %f\n", x, y, sum_of_two_float(x, y));
    }
}
