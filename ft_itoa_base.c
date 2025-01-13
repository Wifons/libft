/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:18 by wifons            #+#    #+#             */
/*   Updated: 2025/01/13 18:56:57 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long num, int base, char is_upper)
{
	static char digits[] = "0123456789abcdef";
	static char digits_upper[] = "0123456789ABCDEF";
	char buffer[50];
	char *result = buffer + 49;

	*result = '\0';
	if (num == 0)
		*--result = '0';
	while (num > 0)
	{
		*(--result) = is_upper ? digits_upper[num % base] : digits[num % base];
		num /= base;
	}
	return (ft_strdup(result));
}
