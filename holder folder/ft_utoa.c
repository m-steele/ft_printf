#include "libft.h"

char	*ft_utoa(unsigned int u)
{
	char			*str;
	int				len;
	unsigned int	ut;

	ut = u;
	len = 0;
	if (u == 0)
		return(ft_strdup("0"));
	while (ut)
		{
			ut /= 10;
			len ++;
		}
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (u % 10) + '0';
		u /= 10;
	}
	return (str);
}