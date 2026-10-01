#include <stdio.h>

int main(void) 
{
int value = 0;
printf("Enter value: ");
scanf("%d",  &value);
printf("Value is %d\n", value);

if (value >= 10 || value <= 20)
{
    printf("value >= 10 || value <= 20 is true\n");
}
if ((10 <= value) <= 20)
{
    printf("10 <= value <= 20 is true\n");
}

if (value >= 10 && value <= 20)
{
    printf("value >= 10 && value <= 20 is true\n");
}

if (value > 10 && value < 20)
{
    printf("value > 10 && value < 20 is true\n");
}

return 0;
}
