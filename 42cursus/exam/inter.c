#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	int k;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	i = 0;
	while (av[1][i] != '\0')
	{
		j = 0;
		while (av[1][i] != av[2][j] && av[2][j] != '\0')
			j++;
		if (av[1][i] == av[2][j])
		{
			k = 0;
			while (av[1][i] != av[1][k] && av[1][k] != '\0')
				k++;
			if (i == k)
				write(1, &av[1][i], 1);
		}
		i++;
	}
}
