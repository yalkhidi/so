#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
    char *name;
    int i;
    int le;
    i = 0;
    name = "yumna";
    le = ft_strlen(name);
    printf("%d\n", le);
    if(name[ft_strlen(name) - 1] == '1')
        printf("null\n");
    else
        printf("no\n");
}