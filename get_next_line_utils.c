/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:17:48 by jutrera-          #+#    #+#             */
/*   Updated: 2022/11/10 11:19:37 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
			i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		len_s1;
	int		len_total;
	int		i;

	len_s1 = ft_strlen(s1);
	len_total = len_s1 + ft_strlen(s2);
	if (len_total == 0)
	{
		free(s1);
		return (NULL);
	}
	dest = (char *)ft_calloc ((len_total + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		dest[i] = s1[i];
	--i;
	while (++i < len_total)
		dest[i] = s2[i - len_s1];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	ft_findnl(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] != '\0')
		return (i);
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			n;
	size_t			i;
	unsigned char	*p;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	p = (unsigned char *)malloc (count * size);
	if (!p)
		return (NULL);
	n = size * count;
	i = -1;
	while (++i < n)
		p[i] = '\0';
	return (p);
}

char	*ft_adjust_buff(char *s, int pos_nl, int i)
{
	int		j;
	char	*aux;
	int		len_s;

	if (!s || (pos_nl == -1 && i == 0))
		return (NULL);
	len_s = ft_strlen(s);
	while (i < len_s)
		s[i++] = 0;
	if (pos_nl == -1)
		pos_nl = ft_strlen(s);
	else
		++pos_nl;
	aux = (char *)ft_calloc(pos_nl + 1, sizeof(char));
	if (!aux)
		return (NULL);
	j = -1;
	while (++j < pos_nl)
		aux[j] = s[j];
	aux[j] = 0;
	return (aux);
}
