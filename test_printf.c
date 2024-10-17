#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
// gcc test_printf.c libftprintf.a libft.a

int main()
{
	char s0[] = "Hey";
	char s1 = 'Y';
	int num = -300;
	int perc = 98;
	char *ptr = "zxcv";
	unsigned int usint = 4294967295;
	unsigned int hexlow = 164531621;
	unsigned int hexupp = 48879;
	const char	*test_str = "%s\n%cou\nint: %i \ndecimal: %d @ %p\nunsigned: %u\nHex Low: %x\nHex UPP: %X\n\n";
	 ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
ft_printf("\n");
		printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

printf("\n");
// ft_printf(" NULL %s NULL ", NULL);
printf("\n");
// printf(" NULL %s NULL ", NULL);
printf("\n");	
	printf("\033[1;91m");
	int printf_count = printf(test_str, s0, s1, num, perc, ptr, usint, hexlow, hexupp);
	printf("printf returned using printf: %d\n", printf_count);
	ft_printf("printf returned using ft_printf: %d\n", printf_count);
	printf("\033[0m\n\n");

	ft_printf("\033[1;36m");
	int ft_printf_count = ft_printf(test_str, s0, s1, num, perc, ptr, usint, hexlow, hexupp);
	printf("ft_printf returned using printf: %d\n", ft_printf_count);
	ft_printf("ft_printf returned using ft_printf: %d\n", ft_printf_count);
	ft_printf("\033[0m");




// ft_printf(" %.3u ", -100);
// printf("\n");
// printf(" %.3u ", -100);
// printf("\n");

printf("\n");
	return(0);
}

//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")
