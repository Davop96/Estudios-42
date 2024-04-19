/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:01:26 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 11:37:41 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*x;

	x = (char *)b;
	while (len > 0)
	{
		*x = (char)c;
		x++;
		len--;
	}
	return (b);
}
/* int	main(void)
{
	char str[60] = "Elon Musk es culpable";

	ft_memset(str, '.', 9 * sizeof(char));
	printf("El tribunal dictamina que el señor %s\n", str);
	return (0);
} */
