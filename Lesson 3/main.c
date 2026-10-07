#include <stdio.h>
#include "summa.h"

int main(void)
{
    printf("Welcome to sum-master!\n");
    int num1 = 0;
    int num2 = 0;

    printf("Enter two positive numbers, us a space between them!\n>");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0 || num2 < 0)
    {
        printf("WAO, you cant read!!!! BYEEEE\n"); 
        return 1;
    }
    
    print_sum_of_two(num1, num2);

    int num3;
    printf("Enter another positive number!\n>");
    scanf("%d", &num3);

    print_sum_of_three(num1, num2, num3);

    float f1;
    float f2;
    printf("Enter three positive decimal numbers with space in between!\n>");
    scanf("%f %f", &f1, &f2);

    print_sum_of_two_floats_n_times(f1, f2, num1);


    
    return 0;
} 