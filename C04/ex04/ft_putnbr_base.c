/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:27:44 by albarre           #+#    #+#             */
/*   Updated: 2023/08/17 13:46:00 by albarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	checkerreur(char *str)

{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = ft_strlen(str);
	if (str[0] == '\0' || c == 1)
		return (0);
	while (str[a] != '\0')
	{
		if (str[a] <= 32 || str[a] == 127 || str[a] == 43 || str[a] == 45)
			return (0);
		b = a + 1;
		while (b < ft_strlen(str))
		{
			if (str[a] == str[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;
	int	erreur;
	long	nb;

	erreur = checkerreur(base);
	l = ft_strlen(base);
	nb = nbr;
	if (erreur == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb < l)
			ft_putchar(base[nb]);
		if (nb >= l)
		{
			ft_putnbr_base(nb / l, base);
			ft_putnbr_base(nb % l, base);
		}
	}
}
int	main(void)
{
	ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(40, "poneyvif");
	printf("\n");
	ft_putnbr_base(896567, "0123456789");
	printf("\n");
	ft_putnbr_base(53, "0123456789abcdef");
}
