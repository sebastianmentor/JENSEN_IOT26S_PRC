#include <stdio.h>

int main(void) 
{
    // int summa = 0;
    // int antal = 5;
    // for (int i = 0; i < antal; i++) 
    // {
    //     int varde;
    //     printf("Ange matvarde: ");
    //     scanf("%d", &varde);
    //     summa += varde;
    // }
    // printf("Medelvarde: %.1f\n", (double)summa / antal);
    // // printf("sista varde = %d\n", varde);
    
    // int x = 0;
    // for (int i = 0; i < 3; i++) 
    // {
    //     x = x + i;
    // }
    // printf("%d\n", x);    

    int max_value = 0;
    
    for(int i = 0; i < 5; i++)
    {
        int user_number;
        printf("Enter integer: ");
        scanf("%d", &user_number);
        if(user_number > max_value || i == 0)
        {
            max_value = user_number;
        }
    }

    printf("Max value is %d\n", max_value);

    return 0;
 }