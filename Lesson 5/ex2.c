#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void inc(int *num);
void add_to(int *a, int b);
void swap(int *num1, int *num2);
void swap_char(char *c1, char *c2);
void skriv_ut(char *my_string);

int main(void) 
{   
    int num1 = 43;
    printf("num1 has address: %p\n", (void *)&num1);
    printf("num1 is now %d\n", num1);
    inc(&num1);
    printf("num1 is now %d\n", num1);
    printf("Lets add 5 to num1!\n");
    add_to(&num1, 5);
    printf("num1 is now %d\n", num1);

    int num2 = 12;
    printf("num1 and num2 is now %d, %d\n", num1, num2);
    swap(&num1, &num2);
    printf("num1 and num2 is now %d, %d\n", num1, num2);

    // for fun

    char my_sentence[] = "Hello, this is a sentence that we will try to sort what ever that might meen!";

    // printf("my_sentence: %s\n", my_sentence);
    skriv_ut(my_sentence);

    int sentence_len = (int)sizeof(my_sentence)/sizeof(my_sentence[0]);

    for(int index = 0; index < sentence_len; index++)
    {
        for(int sub_index = index + 1; sub_index < sentence_len; sub_index ++)
        {
            if (my_sentence[index] < my_sentence[sub_index])
            {
                swap_char(&my_sentence[index], &my_sentence[sub_index]);
            }
        }
    }

    skriv_ut(my_sentence);
    // printf("my_sentence afterwards: %s\n", my_sentence);


    return 0;
}

void inc(int *num)
{   
    printf("num inside inc has address %p\n", (void *)&num);
    printf("num has value inside inc %p\n", (void *)num);
    *num = *num + 1;
}

void add_to(int *a, int b)
{
    *a = *a + b;
}

void swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void swap_char(char *c1, char *c2)
{
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}
void skriv_ut(char *my_string)
{
    printf("%s\n", my_string);
}