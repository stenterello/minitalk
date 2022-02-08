#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_print
{
	int		flags;
	int		width;
	int		space;
	int		dot;
	int		plus;
	int		minus;
	int		hash;
	int		percent;
	int		zero;
	int		prec;
	char	type;
}	t_print;

int		ft_printf(const char *s, ...);

// DEEP ELABORATE UTILS
int		ft_ispercent(char c);
int		ft_deep_elaborate(const char *s, int *i, va_list args);
t_print	ft_init_flags(void);
int		ft_isflag(const char c);
int		ft_istype(char c);
void	ft_take_flag(const char c, t_print *arg);
void	ft_take_parameters(const char *s, int *i, t_print *arg);
void	ft_take_type(const char c, t_print *arg);


// TREAT FUNCTIONS
int		ft_treat_d(va_list args, t_print *arg);
int		ft_treat_c(va_list args, t_print *arg);
int		ft_treat_s(va_list args, t_print *arg);
int		ft_treat_ptr(va_list args, t_print *arg);
int		ft_treat_percent(void);
int		ft_treat_hex(va_list args, t_print *arg);
int		ft_treat_HEX(va_list args, t_print *arg);
int		ft_treat_u(va_list args, t_print *arg);

// SYNTHESIS
int		synthesis(va_list args, t_print *arg);


int		ft_putnbr_u_base(unsigned long long nbr, char *base);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_u_fd(unsigned int n, int fd);
int		ft_puthex(int n, const char *base);
char	*ft_int_to_bin(int data);
char	*ft_reverse_bin(char *convert);
char	*ft_add_one_to_bin(char *convert, int pos);
int		ft_power(int base, int esp);
char	*ft_bin_to_hex(char *convert, char *base);
int		ft_atoi_char(char c);
char	*ft_dec_to_hex(int *values, char *base);
char	*ft_get_hex(int data, char *base);
int		ft_abs_val(int data);
int		ft_long_to_hex(long data);

// NUMBERS LEN
int		ft_unbrlen(unsigned int n);
int		ft_int_nbrlen(int n);
int		ft_dot_nbrlen(int n);
int		ft_ptrnbrlen(size_t n, size_t b_len);
int		ft_hexnbrlen(unsigned int data);


int		ft_putnbr_base_ptr(size_t nbr, char *base);
char	*ft_utoa(unsigned int n);
void	ft_u_putnbr(unsigned int n, char *str, int *i);
void	ft_putnbr(long n, char *str, int *i);
char	*ft_get_pos_hex(int data, char *base);
int		ft_u_base_len(unsigned long long nbr, char *base);

// INTEGERS
char	*ft_create_str(t_print *arg, int data);
void	ft_if_add_zero(t_print *arg, char *str, int data);
int		ft_add_minus(t_print *arg, char *str, int data);
int		ft_no_flag(int data);
void	ft_add_zeroes(t_print *arg, char *ret, int data);
void	ft_handle_minus(t_print *arg, char *text, int data, char *str);
void	ft_handle_width(t_print *arg, char *text, int data, char *str);
void	ft_handle_prec(t_print *arg, char *text, int data, char *str);
void	ft_add_data(t_print *arg, char *str, int data);

// UNSIGNED
char	*ft_create_str_u(t_print *arg, unsigned int data);
void	ft_if_add_zero_u(t_print *arg, char *str, unsigned int data);
int		ft_add_minus_u(t_print *arg, char *str, unsigned int data);
int		ft_no_flag_u(unsigned int data);
void	ft_add_zeroes_u(t_print *arg, char *ret, unsigned int data);
void	ft_handle_minus_u(t_print *arg, char *text, int data, char *str);
void	ft_handle_width_u(t_print *arg, char *text, int data, char *str);
void	ft_handle_prec_u(t_print *arg, char *text, char *str);

// STRINGS
void	ft_add_data_s(t_print *arg, char *str, char *data);
char	*ft_create_str_s(t_print *arg, char *data);
int		ft_no_flag_s(t_print *arg, char *data);

// POINTERS
char	*ft_create_str_ptr(t_print *arg, char *convert);
char	*ft_get_ptr_str(size_t data, char *base);

int		ft_treat_x(va_list args, t_print *arg);
void	ft_handle_min_x(t_print *arg, char *text, char *ret);
void	ft_handle_wid_x(t_print *arg, char *text, char *ret);
void	ft_handle_hash_x(t_print *arg, char *text, char *ret);
char	*ft_utoa_hex(t_print *arg, unsigned int data);
int		ft_no_flag_hex(t_print *arg, unsigned int data);
void	ft_if_add_zero_hex(t_print *arg, char *str, int data);
int		ft_hexnbrlen(unsigned int data);
void	ft_add_zeroes_hex(t_print *arg, char *ret, unsigned int data);
void	ft_handle_prec_x(t_print *arg, char *text, char *ret);
void	ft_handle_zero_x(t_print *arg, char *text, char *ret);
void	ft_set_string(char *ret, char *text, char c, int size);
void	ft_set_string2(char *ret, char *text, t_print *arg);
void	ft_set_string3(char *ret, char *text, char c, int size);

// LONG
int	ft_long_nbrlen(long n);
char	*ft_ltoa(long n);
void	ft_add_data_long(t_print *arg, char *str, long data);
char	*ft_create_str_long(t_print *arg, long data2);
int	ft_treat_long(int data, t_print *arg);
int	ft_add_minus_long(t_print *arg, char *str, long data);
void	ft_prec_aux(char *str, int flag, t_print *arg);
void	ft_handle_minus_long(t_print *arg, char *text, long data, char *str);
void	ft_handle_width_long(t_print *arg, char *text, long data, char *str);
void	ft_handle_prec_long(t_print *arg, char *text, long data, char *str);
void	ft_add_zeroes_long(t_print *arg, char *ret, long data);
void	ft_putlong_fd(long n, int fd);


#endif
