#include <stdio.h>
#include "func.c"

int *bad_func(int value)
{

    int my_value = 2*value;
    if (value < 50)
    {
        my_value += 10;
    }

    printf("bad_func my_value addres %p\n", (void *)&my_value);

    return &my_value;
    
}

int main(void)
{
    int my_value = 42;
    int new_value = identity(my_value);
    int *int_ptr = bad_func(new_value);
    printf("my int_ptr addres %p\n", (void *)&int_ptr);
    printf("my int_ptr value %p\n", (void *)int_ptr);
}