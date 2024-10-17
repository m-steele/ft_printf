#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{


printf(" %x ", 0);
printf("\n");
ft_printf(" %x ", 0);
printf("\n");
//    printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// printf("\n");
// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// printf("\n");


// 	printf("\033[1;91m");
// 	int printf_count = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	printf("\n");
// 	printf("printf returned using printf: %d\n", printf_count);
// 	ft_printf("printf returned using ft_printf: %d\n", printf_count);
// 	printf("\033[0m\n\n");

// 	ft_printf("\033[1;36m");
// 	printf("\n");
// 	int ft_printf_count = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	printf("\n");
// 	printf("ft_printf returned using printf: %d\n", ft_printf_count);
// 	ft_printf("ft_printf returned using ft_printf: %d\n", ft_printf_count);
// 	ft_printf("\033[0m");


	return(0);
}

//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")


// Errors found:
// For /nfs/homes/ekosnick/francinette/tests/printf/printfTester/tests/s_test.cpp:
// 36:     TEST(10, print(" NULL %s NULL ", NULL));

// For /nfs/homes/ekosnick/francinette/tests/printf/printfTester/tests/p_test.cpp:
// 33:     TEST(9, print(" %p %p ", 0, 0));

// For /nfs/homes/ekosnick/francinette/tests/printf/printfTester/tests/x_test.cpp:
// 25:     TEST(1, print(" %x ", 0));
// 49:     TEST(25, print(" %x ", LONG_MIN));
// 53:     TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, 
// ULONG_MAX, 0, -42));

// For /nfs/homes/ekosnick/francinette/tests/printf/printfTester/tests/upperx_test.cpp:
// 25:     TEST(1, print(" %X ", 0));
// 49:     TEST(25, print(" %X ", LONG_MIN));
// 53:     TEST(29, print(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, 
// ULONG_MAX, 0, -42));

// For /nfs/homes/ekosnick/francinette/tests/printf/printfTester/tests/mix_test.cpp:
// 25:     TEST(1, print("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% 
// %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 
// 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 
// 0));

