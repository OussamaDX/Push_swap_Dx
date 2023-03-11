/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:09:22 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/07 15:38:12 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	size_t	i;

	string = (char *)s;
	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != (char)c)
		i++;
	if (string[i] == (char)c)
		return (&string[i]);
	else
		return (NULL);
}
