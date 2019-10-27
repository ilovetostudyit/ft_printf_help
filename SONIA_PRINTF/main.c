
int main()
{
	printf("я распечатал %d символов \n" , ft_printf("my text is : %c\n", 'h'));
    printf("я распечатал %d символов \n" , ft_printf("my text is : %d\n", 42));
    printf("я распечатал %d символов \n" , ft_printf("my text is : %.2d\n", 42));
    printf("я распечатал %d символов \n" , ft_printf("my text is : %.d\n", 42));
    printf("я распечатал %d символов \n" , ft_printf("%.4o", 424242));
    printf("я распечатал %d символов \n" , ft_printf("%s\n", "-why"));
    return(0);
}
