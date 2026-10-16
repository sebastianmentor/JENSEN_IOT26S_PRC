#include <stdio.h>

int main(void) 
{
    int tal1 = 42;
    int tal2 = 22;

    int *ptr1;
    int *ptr2;
    char *big_boss;

    char name[] = "Sebastian";

    big_boss = name;
    ptr1 = &tal1;
    ptr2 = &tal2;

    printf("Adress name: %p\n", (void *)name);
    printf("Adress tal1: %p\n", (void *)&tal1);
    printf("Adress tal2: %p\n", (void *)&tal2);
    printf("Namnet ar: %s\n", name);
    printf("Namnet igen: %s\n", big_boss);
    printf("Varde tal1: %d\n", tal1);
    printf("Varde tal2: %d\n", tal2);

    printf("\n\nNow it all go to hell\n");
    printf("ptr1 has adress: %p\n", &ptr1);
    printf("ptr2 has adress: %p\n", &ptr2);
    printf("ptr1 has value: %p\n", ptr1);
    printf("ptr2 has value: %p\n", ptr2);
    printf("ptr1 points to int value: %d\n", *ptr1);
    printf("ptr2 points to int value: %d\n", *ptr2);

    // lets change tal1 by ptr1
    *ptr1 = 33;

    printf("Varde tal1: %d\n", tal1);

    printf("%d * %d = %d\n", tal1, tal2, tal1 * tal2);
    printf("%d * %d = %d\n", *ptr1, *ptr2, (*ptr1) * (*ptr2));

    // float my_float = 3.1415;
    // ptr1 = &my_float;


    return 0;
}