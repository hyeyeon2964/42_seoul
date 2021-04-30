#include "cub3d.h"

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char *line;
	int err;

	err = 0;
	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s", line);

}
