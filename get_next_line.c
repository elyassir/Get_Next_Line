/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:02:53 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/04 20:03:40 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    static char *buff = NULL;
    static char tmp[BUFFER_SIZE + 1];
    int i = 0;
    int count = read(fd, tmp, BUFFER_SIZE);
    int stope = 1;
    tmp[BUFFER_SIZE] = '\0';
    if (buff != NULL)
        buff = ft_strjoin(buff, tmp);
    else
        buff = ft_strdup(tmp);
    while (stope)
    {
        i = ft_strchr(buff, '\n');
        if (i != -1)
        {
            char *s1 = ft_substr(buff, 0, i);
            buff = ft_substr(buff, i + 1, count - i);
            return (s1);
        }
        count += read(fd, tmp, BUFFER_SIZE) + 1;
        buff = ft_strjoin(buff, tmp);
    }
    return ("(null)");
}

// int main()
// {
//     int fd = open("text.txt", O_RDONLY);

//     printf("line1 = %s\n", get_next_line(fd));
//     printf("\n\n\n");
//     printf("line2 = %s\n", get_next_line(fd));
//     printf("\n\n\n");
//     printf("line3 = %s\n", get_next_line(fd));
//     printf("\n\n\n");
//     printf("line4 = %s\n", get_next_line(fd));
// }