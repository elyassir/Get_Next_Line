/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:03:54 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/04 20:03:55 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char )c;
	i = 0;
	while (s[i])
	{
        //printf("%c%d\n", i);
		if (s[i] == cc)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*new_string;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = malloc((len_s1 + len_s2 + 1) * sizeof(char ));
	if (!new_string)
		return (NULL);
	while (++i < len_s1)
		new_string[i] = s1[i];
	while ((len_s1 + len_s2) > (i + ++j))
		new_string[i + j] = s2[j];
	new_string[i + j] = '\0';
    free(s1);
	return (new_string);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	while (i < len && i + start < s_len)
		i++;
	d = malloc((i + 1) * sizeof(char ));
	if (!d)
		return (NULL);
	i = 0;
	while (i < len && i + start < s_len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// char	*ft_freebuff(char *s, unsigned int start)
// {
// 	char			*d;
// 	size_t			i;
// 	unsigned int	s_len;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	while (i + start < s_len)
// 		i++;
// 	d = malloc((i + 1) * sizeof(char ));
// 	if (!d)
// 		return (NULL);
// 	i = 0;
// 	while (i + start < s_len)
// 	{
// 		d[i] = s[start + i];
// 		i++;
// 	}
// 	d[i] = '\0';
// 	free(s);
// 	return (d);
// }