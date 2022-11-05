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
    char *buff = NULL;
    static char tmp[BUFFER_SIZE + 1];
    int i = 0;
    int count = read(fd, tmp, BUFFER_SIZE);
    int stope = 1;
    tmp[BUFFER_SIZE] = '\0';
    if (!buff == NULL)
        buff = ft_strjoin(buff, tmp);
    else
        buff = ft_strdup(tmp);
    while (stope)
    {
        i += ft_strchr(tmp, '\n');
        if (ft_strchr(tmp, '\n') != -1)
        {
            printf("|%d|\n", i);
            printf("|%d|\n", i);
            //buff = ft_substr(buff, i, ft_strlen(buff) - i);
            return(ft_substr(buff, 0, i));
        }
        i += BUFFER_SIZE + 1;
        //i += BUFFER_SIZE + 1;
        count = read(fd, tmp, BUFFER_SIZE);
        buff = ft_strjoin(buff, tmp);
    }
    return ("(null)");
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    printf("result = |%s|\n", get_next_line(fd));
    printf("result = |%s|\n", get_next_line(fd));
    printf("result = |%s|\n", get_next_line(fd));
}