#include <stdio.h>

// Skriv Torrt under 30, Bra från 30 till 60 och annars Fuktigt.
// Testa 29, 30, 60 och 61.
// Vi ska också testa -23 och 101 som är ogiltgliga värden

int main(void) 
{
int humidity = 0;
printf("Luftfuktighet i procent: ");
scanf("%d", &humidity);

/* Fyll i villkoren. */

if (humidity < 0)
{
    printf("Now valid!\n");
}
else if (humidity > 100)
{
    printf("Not valid!\n");
}
else if (humidity > 60)
{
    printf("Fuktigt\n");
}
else if (humidity >= 30)
{
    printf("Bra\n");
}
else
{
    printf("Torrt\n");
}

return 0;
}
