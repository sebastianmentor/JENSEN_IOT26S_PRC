#include <stdio.h>

int main(void)
{   
    int favorit_number = 23;
    float favorit_float = 0.1234567;
    char favorit_char = 'a';

    printf("Favorit number: %10d\nFavorit char:%c\nFavorit float:%.2f\n", favorit_number, favorit_char, favorit_float);

    return 0;
}