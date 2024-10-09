#include <unistd.h>
#include <stdio.h>
// JUNKJUNKJUNKJUNKJUNKJUNKJUNKJUNK
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	f_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int main()
{
	char str[]="Y nasdasgasg";
	f_putstr(str);
	write(1, "\n", 1);
	ft_putstr(str);
	write(1, "\n", 1);
return(0);
}