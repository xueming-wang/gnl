/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:45:37 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/27 14:37:30 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*int main()
{
    int fd1;
    int fd2;
    int fd3;
    char *line;

    fd1 = open("./test1", O_RDONLY);
    fd2 = open("./test2", O_RDONLY);
    fd3 = open("./test3", O_RDONLY);

         printf("第一轮\n\n");

        get_next_line(fd1, &line);
        printf("fd1 : %d line : %s\n",fd1 ,line);
        free(line);

        get_next_line(fd3, &line);
        printf("fd3 : %d line : %s\n",fd3 ,line);
        free(line);
    
        get_next_line(fd2, &line);
        printf("fd2 : %d line : %s\n",fd2 ,line);
        free(line);

        printf("\n\n第二轮\n\n");

        get_next_line(fd3, &line);
        printf("fd3 : %d line : %s\n",fd3 ,line);
        free(line);

        get_next_line(fd1, &line);
        printf("fd1 : %d line : %s\n",fd1 ,line);
        free(line);
    
        get_next_line(fd2, &line);
        printf("fd2 : %d line : %s\n",fd2 ,line);
        free(line);
    

    return (0);
}*/

int main(int ac, char **av)
{
	(void)ac;
	
	int fd = open(av[1], O_RDONLY);	
    int i = 0;
    while (i <= 10)
	{
        get_next_line(fd, &av[1]);
		printf("%s\n", av[1]);
        i++;
    }
	/*get_next_line(fd, &av[1]);
	printf("%s\n", av[1]);
    get_next_line(fd, &av[1]);
	printf("%s\n", av[1]);
    get_next_line(fd, &av[1]);
	printf("%s\n", av[1]);
    get_next_line(fd, &av[1]);
	printf("%s\n", av[1]);
    get_next_line(fd, &av[1]);
	printf("%s\n", av[1]);*/
	return 0;
}


