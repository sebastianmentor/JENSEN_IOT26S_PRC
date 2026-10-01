#include <stdio.h>

int main(void) {
    int num1 = 5;
    int num2 = 2;
    int whole = num1 / num2;

    double num3 = 5.0;
    double num4 = 2.0;
    double decimal = num3/num4;
    printf("Integer division: %d\n", whole);
    printf("Floating-point division: %.1f\n", decimal);
    return 0;
}