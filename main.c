#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
    (void)ac;
    int fd;
    char *line;

    fd = open(av[1], O_RDONLY);
    int r = 1;
    while (r > 0)
    {
        r = get_next_line(fd, &line);
        printf("%s\n", line);
        free(line);
    }
    getchar();
    return (0);
}