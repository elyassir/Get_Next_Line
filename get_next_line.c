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
//#include <stdio.h>


char *get_next_line(int fd)
{
    char *buff = NULL;
    static char tmp[BUFFER_SIZE + 1];
    int search = -1;
    int count2;
    int count = read(fd, tmp, BUFFER_SIZE);
    if (count <= 0 || fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp[BUFFER_SIZE] = 0;
    //printf("%d\n", count);
    //printf("%s\n", tmp);
    if (!tmp[0])
        buff = ft_strjoin(buff, tmp);
    else // khawi
        buff = ft_strdup(tmp);
    count2 = count;
    while (count)
    {
        search = ft_strchr(buff, '\n');
        //printf("search = %d\n", search);
        if (search != -1 || count2 == 0)
        {
            char *s1;
            if (search == -1)
                s1 = ft_substr(buff, 0, count - 1);
            else
                s1 = ft_substr(buff, 0, search + 1); /// mn 0 htal \n
            //printf("count = %d || search = %d\n", count, search);
            //printf("s1[0] = %d ,s1[1] = %d\n", s1[0], s1[1]);
            free(buff);
            return (s1);
        }
        count += count2;
        count2 = read(fd, tmp, BUFFER_SIZE);
        if (count2 < 0)
            return (NULL);
        if (count2 != 0)
        buff = ft_strjoin(buff, tmp);
    }

    return (NULL);
}

// int main()
// {
//     int fd = open("files/41_with_nl", O_RDWR);

//     printf("line1 = |%s|\n", get_next_line(fd));
//     printf("\n");
//     printf("line2 = %s\n", get_next_line(fd));
// //     printf("\n\n\n");
// //     printf("line3 = %s\n", get_next_line(fd));
// //     printf("\n\n\n");
// //     printf("line4 = %s\n", get_next_line(fd));
// }