/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:18 by wifons            #+#    #+#             */
/*   Updated: 2025/01/13 20:07:39 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int validate_base(const char *base, int *base_len)
{
	int	i;

	*base_len = ft_strlen(base);
	if (*base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (!ft_isprint(base[i]) || ft_strchr(base + i + 1, base[i]))
			return (0);
		i++;
	}
	return (1);
}

static int get_n_len(long num, int base_len)
{
	int	len;

	len = (num <= 0);
	while (num)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

static int handle_zero_case(char *result, long n, const char *base)
{
	if (n == 0)
	{
		result[0] = base[0];
		return (1);
	}
	return (0);
}

static long handle_sign(char *result, long n)
{
	if (n < 0)
	{
		result[0] = '-';
		return (-n);
	}
	return (n);
}

static void convert_to_base(char *result, long n, const char *base, int base_len, int len)
{
	while (n)
	{
		result[--len] = base[n % base_len];
		n /= base_len;
	}
}

char	*ft_itoa_base(int num, const char *base)
{
	int		base_len;
	int		n_len;
	char	*result;
	long	n;

	n = num;

	if (!validate_base(base, &base_len))
		return (NULL);
	n_len = get_n_len(n, base_len);
	result = ft_calloc(n_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (handle_zero_case(result, n, base))
		return (result);
	n = handle_sign(result, n);
	convert_to_base(result, n, base, base_len, n_len);
	return (result);
}
