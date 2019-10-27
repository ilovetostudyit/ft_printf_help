
#include "../ft_printf.h"

static void		turn_into_char(char *res, long long n,
								int base, int num_d)
{
	char	*buf;
	int		sign;

	buf = "0123456789abcdef";
	sign = 1;
	if (n < 0)
		sign = -1;
	res[num_d--] = '\0';
	while (n)
	{
		res[num_d--] = buf[(n % base) * sign];
		n /= base;
	}
}

static void		turn_into_char_ll(char *res, uintmax_t n,
							   int base, int num_d)
{
	char	*buf;
	
	buf = "0123456789abcdef";
	res[num_d--] = '\0';
	while (n)
	{
		res[num_d--] = buf[n % base];
		n /= base;
	}
}

char			*ft_itoa_base_ll(uintmax_t n, int base)
{
	char	*res;
	int		num_d;
	
	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
	}
	else
	{
		num_d = ft_num_dig(n, base);
		if (!(res = (char *)malloc(sizeof(char) * (num_d + 1))))
			return (NULL);
		turn_into_char_ll(res, n, base, num_d);
	}
	return (res);
}


char			*ft_itoa_base(long long n, int base)
{
	char	*res;
	int		num_d;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0 || base == 10)
		res = ft_itoa(n);
	else
	{
		num_d = ft_num_dig(n, base);
		if (!(res = (char *)malloc(sizeof(char) * (num_d + 1))))
			return (NULL);
		turn_into_char(res, n, base, num_d);
	}
	return (res);
}
