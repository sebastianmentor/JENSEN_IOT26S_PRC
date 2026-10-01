#include <stdio.h>

int main(void)
{
    int age = 77;
    printf("Hello world!\n"); 
    printf("Hello Sebastian!\n");
    printf("Your age is %d\n", age);
    printf("Lets get the true age! Enter your age:");
    scanf("%d", &age);
    printf("your true age is %d\n", age);
    return 0;
}