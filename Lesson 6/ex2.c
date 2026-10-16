#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FIRST_ARR_SIZE 4
#define SECOND_ARR_SIZE 10

void print_arr_int(int *ptr, int arr_size);
void fill_arr_int(int *ptr, int arr_size);
bool increase_int_arr(int **ptr, int new_size);

int main(void) 
{   
    int *sensorer = malloc(FIRST_ARR_SIZE * sizeof(int));

    if (sensorer == NULL)
    {
        free(sensorer);
        return 1;

    }  

    printf("sensorer contains address %p\n", (void *)sensorer);
    print_arr_int(sensorer, FIRST_ARR_SIZE);
    fill_arr_int(sensorer, FIRST_ARR_SIZE);
    print_arr_int(sensorer, FIRST_ARR_SIZE);

    int *tmp = realloc(sensorer, SECOND_ARR_SIZE * sizeof(int));

    if (tmp == NULL) 
    {
        free(sensorer);
        return 1;
    }

    sensorer = tmp;
    tmp = NULL;
    
    printf("After realloc sensorer contains address %p\n\n", (void *)sensorer);
    print_arr_int(sensorer, SECOND_ARR_SIZE);

    printf("Try to increase from function!\n");
    if (increase_int_arr(&sensorer, SECOND_ARR_SIZE + FIRST_ARR_SIZE))
    {
        printf("Success, we have more memory!\n\n");
        print_arr_int(sensorer, SECOND_ARR_SIZE + FIRST_ARR_SIZE);
    }
    else
    {
        printf("Fail to reallocate from funtion!");
    }

    free(sensorer);
    sensorer = NULL;
    free(sensorer);

    printf("After free(sensorer)\n");
    print_arr_int(sensorer, SECOND_ARR_SIZE);
    printf("tmp still knows the address!!!\n");
    print_arr_int(tmp, SECOND_ARR_SIZE);

    return 0;
}

void print_arr_int(int *ptr, int arr_size)
{   
    if (ptr==NULL)
    {   
        printf("HOLY SHIT!! Pointer points to NULL!!\n");
        return;
    }
    for(int i=0; i < arr_size; i++)
    {
        printf("Addres:%p contains value %d\n", (void *)(ptr + i), ptr[i]);
    }
}

void fill_arr_int(int *ptr, int arr_size)
{
    if (ptr==NULL)
    {   
        printf("HOLY SHIT!! Pointer points to NULL!!\n");
        return;
    }
    for(int i=0; i < arr_size; i++)
    {
        *(ptr + i) = i;
    }
}

bool increase_int_arr(int **ptr, int new_size)
{
    if(ptr == NULL)
    {
        return false;
    }

    int *tmp = realloc(*ptr, new_size * sizeof(int));
    if (tmp == NULL)
    {
        return false;
    }
    *ptr = tmp;
    return true;
}