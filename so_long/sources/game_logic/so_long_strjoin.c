/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:35:22 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/22 19:55:08 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

char	*ft_strjoin_so_long(char *s1, char *s2)
{
	char	*str_new;
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	str_new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str_new)
		return (NULL);
	while (s1 && s1[index])
	{
		str_new[index] = s1[index];
		index++;
	}
	while (*s2)
	{
		str_new[index] = *s2;
		index++;
		s2++;
	}
	str_new[index] = '\0';
	return (str_new);
}
