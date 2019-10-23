#include "ft_printf.h"
int main()
{
    printf("я распечатал %d символов \n" , ft_printf("meow, %s\n%d\n", "hello, world!", 42));
    
    return(0);
}
