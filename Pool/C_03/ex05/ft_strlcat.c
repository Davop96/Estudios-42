/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:41:42 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:35:52 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (*(str + x) != '\0')
	{
		x++;
	}
	return (x);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srcx;
	unsigned int	destx;
	unsigned int	x;

	srcx = ft_strlen(src);
	destx = ft_strlen(dest);
	x = 0;
	if (destx < size)
		srcx += destx;
	else
		srcx += size;
	if (size > 0)
	{
		while (*(src + x) && (x + destx) < size - 1)
		{
			*(dest + x + destx) = *(src + x);
			x++;
		}
		*(dest + destx + x) = '\0';
	}
	return (srcx);
}

/* int	main(void)
{
	char	dest[] = "friend";
	char	src[] = "hello";
	unsigned int	size;

	size = 10;
	printf("%u\n", ft_strlcat(dest, src, size));
	return (0);
}
 */