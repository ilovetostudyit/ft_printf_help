#include "ft_printf.h"
int main()
{
    printf("я распечатал %d символов \n" , ft_printf("%s\n", "hello, world!"));
    
    return(0);
}