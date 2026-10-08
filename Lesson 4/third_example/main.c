#include <stdio.h>
#include <string.h>

int my_len_func(char arr[])
{
    int len = 0;
    int index = 0;
    while (arr[index] != 0)
    {
        len ++;
        index ++;
    }

    return len;
    
}

int main(void)
{
    char my_char[10] = "b"; // {'b', '\0'}
    char hello[10] = {'h', 'e', 'l', 'l', 'o'};
    char hello2[10] = "hello2";
    printf("my_char is %s\n", my_char);
    printf("size of my_char: %zu\n", sizeof(my_char));
    printf("hello from %s\n", hello);
    printf("hello2 from %s\n", hello2);

    char namn[20];
    printf("Ange sensornamn: ");
    scanf("%19s", namn);
    printf("Hej %s!\n", namn);

    printf("my_char is %s\n", my_char);
    printf("size of my_char: %zu\n", sizeof(my_char));
    printf("hello from %s\n", hello);
    printf("hello2 from %s\n", hello2);

    char new_namn[20];
    printf("Ange sensornamn 2: ");
    scanf("%3s", new_namn);
    printf("Hej %s!\n", new_namn);

    printf("len of hello is %d", my_len_func(hello));

    printf("Test hej vs hejsan %d", strcmp("hejsan", "hej"));
    
    return 0;
}