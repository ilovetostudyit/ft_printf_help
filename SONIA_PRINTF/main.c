#include "ft_printf.h"
int main()
{
    printf("мне вернулось %d\n" , ft_printf("%s\n", "hello, world!"));
    
    return(0);
}