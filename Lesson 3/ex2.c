#include <stdio.h>

int tal;

void print_global_tal();
void inc_global_tal();
void oka();

int main(void) 
{   
    print_global_tal();
    int tal = 5;
    oka();
    printf("I main efterat: %d\n", tal);
    print_global_tal();
    return 0;
}

void print_global_tal()
{
    printf("Global tal is %d\n", tal);
}


void oka() 
{   
    int tal = 3;
    tal = tal + 1;
    printf("Inne i funktionen: %d\n", tal);
    inc_global_tal();
}

void inc_global_tal()
{
    tal++;
}
