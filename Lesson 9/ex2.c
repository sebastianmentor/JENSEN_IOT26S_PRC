#include <stdio.h>

typedef struct {
    int id;
    int building;
    int redings[100];
}Sensor;

void dubbla_with_ptr(Sensor *s) 
{
    printf("s.id=%d\ns.building=%d\n",s -> id, s -> building);
    printf("####################################");
    for(int i = 0; i<10; i++)
    {
        printf("Start s.reading[i]=%d\n",s -> redings[i]);
        s -> redings[i] = s -> redings[i] * 3;
        printf("After s.reading[i]=%d\n",s -> redings[i]);
    }
    printf("####################################");
}

void dubbla(Sensor s) 
{
    printf("s.id=%d\ns.building=%d\n",s.id, s.building);
    printf("####################################");
    for(int i = 0; i<10; i++)
    {
        printf("Start s.reading[i]=%d\n",s.redings[i]);
        s.redings[i] = s.redings[i] * 3;
        printf("After s.reading[i]=%d\n",s.redings[i]);
    }
    printf("####################################");
}

Sensor create_sensor(int id, int building)
{
    Sensor s = {id, building};

    for(int i = 0; i<100; i++)
    {
        s.redings[i] = i+1;
    }

    return s;
}

int main(void) 
{
    // Sensor s1 = {1, 8, {1,2,3,4,5,6,7,8,9,10}};
    Sensor s1 = create_sensor(23, 2);

    // dubbla(s1);
    printf("%d\n", s1.id);
    printf("%d\n", s1.building);

    for(int i = 0; i<20; i++)
    {
        printf("s.reading[i]=%d\n",s1.redings[i]);
    }

    // dubbla_with_ptr(&s1);

    // for(int i = 0; i<20; i++)
    // {
    //     printf("s.reading[i]=%d\n",s1.redings[i]);
    // }

    return 0;
}