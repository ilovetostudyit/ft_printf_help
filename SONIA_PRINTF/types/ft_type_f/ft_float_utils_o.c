#include "../../ft_printf.h"

char	*ft_un(char *main, char *s)
{
	char	*tmp_c;

	tmp_c = main;
	if (*s == '-')
		main = ft_strjoin(s, main);
	else
		main = ft_strjoin(main, s);
	free(tmp_c);
	return (main);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
