#include <stdio.h>

int main(void) 
{
    int sum = 0;
    int user_input = 0;

    printf("Boxnumber %p\n", (void*)&user_input);

    for (int i = 1; i < 6; i++)
    {   
        user_input = 0;
        printf("Enter the number: ");
        fflush(stdout);
        int number_of_scans = scanf("#%d", &user_input);

        if (number_of_scans != 1)
        {
            printf("Not a valid number! Please, try again!\n");
            i--;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
                // kasta bort tecken
        }

        sum += user_input;

    }
    /* Las exakt fem heltalsmatningar. */
    /* Skriv ut medelvardet som decimal. */

    printf("Total is %d and avrage is %.2f\n", sum, (float)sum/5);
    
    return 0;
}