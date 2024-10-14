#include "libft.h"

char	*ft_itolowhex(unsigned long num)
{
	char			*str;
	char			*hex;
	unsigned long	x;
	int				len;

	hex = "0123456789abcdef";
	x = num;
	len = 1;
	while (x /= 16)
		len++;
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}