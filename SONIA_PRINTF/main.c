#include "ft_printf.h"
int main()
{
    printf("я распечатал %d символов \n" , ft_printf("my text is :%s\n", "hello, world!", 42));
    
    return(0);
}
