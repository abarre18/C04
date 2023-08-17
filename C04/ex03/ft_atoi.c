/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:10:45 by albarre           #+#    #+#             */
/*   Updated: 2023/08/15 12:35:30 by albarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	whitespace(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while((str[i] >= 9 && str[i] <= 13 ) || str[i] == 32)
	i++;
	while((str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = whitespace(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		 result *= 10;
		 result += str[i] -48;
		 i++;
	}
	result *= sign;
	return (result);
}

int	main(void)
{
	char *s = " ---+--+1234ab567";
	printf("%d", ft_atoi(s));
	return (0);
}
