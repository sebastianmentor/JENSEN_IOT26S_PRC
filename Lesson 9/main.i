# 0 ".\\main.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 ".\\main.c"
# 1 ".\\func.c" 1
int identity(int value)
{
    if(value < 12)
    {
        return value + 1;
    }
    return value;
}
# 2 ".\\main.c" 2

int main(void)
{
    int my_value = 42;
    int new_value = identity(my_value);
}
