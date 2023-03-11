/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:07:32 by ooussaad          #+#    #+#             */
/*   Updated: 2022/10/25 20:39:37 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int x, size_t n)
{
	char			*p;
	unsigned int	i;

	i = 0;
	p = b;
	while (n > i)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (p);
}
