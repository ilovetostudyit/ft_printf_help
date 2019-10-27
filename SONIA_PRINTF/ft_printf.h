#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_buf
{
	size_t			top;
	size_t			size;
	int				err;
	char			*buf;
}					t_buf;

typedef struct		s_param
{
	unsigned char	length;
	char			minus;
	char			plus;
	char			zero;
	char			hash;
	char			space;
	int				width;
	int				precision;
}					t_param;

# define BUF_SIZE 1000
# define DOTA_S 10000
# define BASE_INT 10

typedef	__uint128_t	t_uint128;

typedef struct		s_lnum
{
	unsigned char	lnum[DOTA_S];
	int				size;
}					t_lnum;


void			ft_lnum_new(t_lnum *a);
void			ft_lnum_plus(t_lnum *a, t_lnum b);
void			ft_lnum_plus2(t_lnum *a, int b);
void			ft_lnum_mul(t_lnum *a, int b);
int				ft_printf(char *str, ...);
size_t          ft_get_res(t_buf *buf, t_param *param, char **str, va_list ap);
void            ft_buf_init(t_buf *buf);
char			*ft_strnew(size_t size);
void            *ft_memset(void *b, int c, size_t len);
void			*ft_memset_char(char *str, t_param param, char c);
void            ft_printf_init(t_buf *buf, t_param *param);
void            ft_param_init(t_param *param);
void			ft_free_buf(t_buf *buf);
void            ft_print_res(t_buf *buf);
void			ft_buf_add_s(t_buf *new, char *str, int flag); //я тут ненадолго
void			ft_buf_add_nc(t_buf *new, wchar_t c); // я тоже :) 
void			ft_buf_add_ns(t_buf *new, char *str, size_t n, int flag); //и я
void            ft_percent_main(t_buf *buf, t_param param, char **str, va_list ap);
void            ft_colour_main(char **str, t_buf *buf);
void            ft_print_else(t_buf *buf, char str);
int				ft_param_fill(t_param *param, char **str, va_list ap);
void			ft_null_str_buf(char *str);

void			ft_type_c(t_param param, char c, t_buf *buf);
void			ft_type_c_up(t_param param, wchar_t c, t_buf *buf);
void			ft_type_d(t_param param, va_list ap, t_buf *buf);
void			ft_type_d_up(t_param param, va_list ap, t_buf *buf);
void			ft_type_f(t_param param, va_list ap, t_buf *buf);
void			ft_type_f_up(t_param param, va_list ap, t_buf *buf);
void			ft_type_o(t_param param, va_list ap, t_buf *buf);
void			ft_type_o_up(t_param param, va_list ap, t_buf *buf);
void			ft_type_p(t_param param, void *ptr, t_buf *buf);
void			ft_type_percent(t_param param, t_buf *buf);
void			ft_type_s_up(t_param param, wchar_t *ap, t_buf *buf);
void			ft_type_s(t_param param, char *ap, t_buf *buf);
void			ft_type_u(t_param param, va_list ap, t_buf *buf);
void			ft_type_u_up(t_param param, va_list ap, t_buf *buf);
void			ft_type_x(t_param param, va_list ap, t_buf *buf);
void			ft_type_x_up(t_param param, va_list ap, t_buf *buf);

int				ft_get_prec(t_param *param, char **str,va_list ap);
void			ft_get_length(t_param *param, char **str);
int 			ft_get_width(t_param *param, char **str,va_list ap);
void			ft_get_width_main(t_param *param, char **str, va_list ap);
void 			ft_get_flags(t_param *param, char **str);
int				ft_get_prec_main(t_param *param, char **str,va_list ap);
void			ft_get_other_flags(t_param *param, char **str);
char			*ft_itoa_base(long long n, int base);
int				ft_atoi(const char *str);
char			*ft_itoa(long long n);
void			ft_print_d(t_param param, char *i, t_buf *buf);
int				ft_num_dig(uintmax_t n, int base);
size_t			ft_strlen(const char *s);
void			ft_space_check(char *str, t_param *param, t_buf *buf);
void			ft_tire_check(char *str, t_buf *buf);
void			ft_plus_check(char *str, t_param *param, t_buf *buf);
char			*ft_memnew(size_t i, int lett);
int				ft_putchar(unsigned long long c, char *str);
void			ft_zero_check(char *str, t_param *param, t_buf *buf);
char			*ft_itoa_base_ll(uintmax_t n, int base);
void			ft_type_p_zero(t_param param, int len, t_buf *buf);
void			ft_type_p_minus(t_param param, char *str, int len, t_buf *buf);
void			ft_type_p_else(t_param param, char *str, int len, t_buf *buf);
void    		fill_with_zeros(t_param *param, t_buf *buf, int len);
void			p_precision_check(t_param *param, t_buf *buf, int len);
void			ft_type_s_prec_pos(t_param param, char *ap, int tmp, t_buf *buf);
void			ft_type_s_minus(t_param param, char *ap, int tmp, t_buf *buf);
void			ft_type_s_prec_neg(t_param param, char *ap, int tmp, t_buf *buf);
void    		s_ap_check(t_buf *buf, char *ap);
void   			s_width_check(t_param param, char *ap, int tmp, t_buf *buf);
void    		s_pres_ap_check(t_param param, char *ap, int tmp, t_buf *buf);
void    		s_pres_width_check(t_param param, char *ap, int tmp, t_buf *buf);
void			ft_print_o(t_param param, char *str, t_buf *buf);
void			prec_pos_null(char *str, t_param param, t_buf *buf);
void			prec_neg_null(char *str, t_param param, t_buf *buf);
void   			o_hash_check(t_param *param, t_buf *buf);
void    		o_minus_check(t_param *param, t_buf *buf, int tmp);
void    		o_minus_zero(t_param *param, t_buf *buf, int tmp);
void    		o_prec_check(t_param *param, t_buf *buf, int tmp);
void			ft_print_u(t_param param, char *ap, t_buf *buf);
void    		u_prec_tmp_check(t_param param, t_buf *buf, int tmp);
void			ft_print_x(t_param param, char *str, t_buf *buf);
void			ft_type_x_up(t_param param, va_list ap, t_buf *buf);
void    		ft_print_x_up(t_param param, char *str, t_buf *buf);
void			minus_pos_null(t_param param, char *str, int tmp, t_buf *buf);
void			minus_neg_null(t_param param, char *str, int tmp, t_buf *buf);

char			*ft_float_f(long double f, int precision);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strndup(const char *s1, size_t n);
int				ft_max(int a, int b);
char			*ft_un(char *main, char *s);
void			ft_len_frac_more_prec(int tmp, int prec, char **frac);
void			ft_zero_m_e(char **main, char **frac);
void			ft_bigint_ulong(int e,\
				unsigned long long m, char **main, char **frac);
void			ft_max_min_bigint(int e,\
				unsigned long long m, char **main, char **frac);

	

