#include <unistd.h>

void	st_putchar(char c)
{
	write(1, &c, 1);
}

void	st_putnbr(int nb)
{
	int	sign;

	sign = -1;
	if (nb == -2147483648)
	{
		st_putnbr(nb / 10);
		st_putnbr(8);
	}
	else if (nb < 0)
	{
		st_putchar('-');
		nb = nb * sign;
		st_putnbr(nb);
	}
	else
	{
		if (nb < 10)
			st_putchar(nb + '0');
		else
		{
			st_putnbr(nb / 10);
			st_putchar(nb % 10 + '0');
		}
	}
}
