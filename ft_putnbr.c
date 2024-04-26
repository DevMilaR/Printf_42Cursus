/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:49:41 by lromano           #+#    #+#             */
/*   Updated: 2024/02/28 11:34:20 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned long n, char *base)
{
	size_t	base_len;
	int		len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	len = 0;
	if (n >= base_len)
		len += ft_putnbr(n / base_len, base);
	len += ft_putchar(base[n % base_len]);
	return (len);
}

int	ft_signed_putnbr(long n)
{
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n, DEC));
	else
		return (ft_putnbr(n, DEC));
}
