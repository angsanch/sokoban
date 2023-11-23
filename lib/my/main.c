#include <stdio.h>
#include "include/my.h"

int report_error(char *str)
{
    int i = 0;

    while(str[i]){
        write(1, str + i, 1);
        i ++;
    }
    return (84);
}

int main(int argc, char **argv)
{
    int my_r;
    int r;

    if (argc != 2)
        return (report_error("Incorrect amount of parameters.\n"));
    my_r = my_printf(argv[1], argv[0]);
    my_putchar('\n');
    r = printf(argv[1], argv[0]);
    printf("\n %d %d\n", my_r, r);
}
