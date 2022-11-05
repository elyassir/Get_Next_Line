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
    int count2;
    int count = read(fd, tmp, BUFFER_SIZE);
    if (count <= 0)
        return (NULL);
    int stope = 1;
    tmp[BUFFER_SIZE] = '\0';
    if (buff != NULL)
        buff = ft_strjoin(buff, tmp);
    else if (buff == NULL)
        buff = ft_strdup(tmp);
    while (stope)
    {
        i = ft_strchr(buff, '\n');
        count += count2;
        if (i != -1 || count2 == 0)
        {
            char *s1;
            printf("%d\n", count);
            printf("%s\n", buff);
            if (i == -1)
                s1 = ft_substr(buff, 0, count - 1);
            else
                s1 = ft_substr(buff, 0, i + 1);
            buff = ft_substr(buff, i + 1, count - i + 1);
            return (s1);
        }
        count2 = read(fd, tmp, BUFFER_SIZE);
        if (count2 < 0)
            return (NULL);
        if (count != 0)
            buff = ft_strjoin(buff, tmp);
        printf("%s\n", buff);
    }

    return (NULL);
}

int main()
{
    int fd = open("files/41_no_nl", O_RDWR);

    printf("fd = %d\nline1 = |%s|\n", fd, get_next_line(fd));
    printf("\n\n\n");
    printf("line2 = %s\n", get_next_line(fd));
//     printf("\n\n\n");
//     printf("line3 = %s\n", get_next_line(fd));
//     printf("\n\n\n");
//     printf("line4 = %s\n", get_next_line(fd));
}