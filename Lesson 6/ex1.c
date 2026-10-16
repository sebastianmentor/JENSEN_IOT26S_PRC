#include <stdio.h>
#include <stdlib.h>



int main(void) 
{
    int antal = 0;
    printf("Enter number of numbers (1-10):\n>");
    scanf("%d", &antal);

    if(antal < 1 && antal > 10)
    {
        printf("MR fail! Good bye!\n");
        return 1;
    }

    //printf("*antal gives %d\n", *antal); //Fungerar inte! 

    printf("antal * sizeof(int) = %zu\n", antal * sizeof(int));
    int *sensorer = malloc(antal * sizeof(int));

    if(sensorer == NULL)
    {
        printf("ERROR! Fail to allocate memory!\n");
        return 1;
    }

    printf("The address of sensorer is %p\n", (void *)sensorer); 
    printf("sensorer[0] before assigment is %d\n", *sensorer);
    sensorer[0] = 21;
    printf("%d\n", sensorer[0]);

    for(int i = 0; i < antal; i++)
    {
        printf("We have that sensorer[%d] gives %d\n", i, sensorer[i]);
        printf("We have that *(sensorer + %d) gives %d\n", i, *(sensorer + i));
    }

    printf("The question? Can we do sensorer[-1] = %d\n", sensorer[-1]);
    printf("&sensorer[-1] gives %p\n", (void*)&sensorer[-1]);
    // sensorer[-1] == *(sensorer + (-1))
    printf("(sensorer + (-1)) gives %p\n", (void*)(sensorer + (-1)));
    printf("*(sensorer + (-1)) gives %d\n", *(sensorer + (-1)));

    int *mid_ptr = &sensorer[antal/2];

    printf("mid_ptr has value: %p\n", (void *)mid_ptr);

    for(int i = 0; i > (antal/2 - antal); i--)
    {
        printf("mid_ptr[%d] = %d\n", i, mid_ptr[i]);
    }

    free(sensorer);
    return 0;
}

