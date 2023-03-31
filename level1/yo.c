#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int	main(void)
{
	char	*line;
	FILE *fd = fopen("input", "r");
	size_t	i = 0;

	line = NULL;
	getline(&line, &i, fd);
	int	loops = atoi(line);
	int output = open("output", O_CREAT | O_WRONLY, 0777);
	for (int j = 0; j < loops; j++)
	{
		getline(&line, &i, fd);
		if (line[0] == line[1])
			write(output, &line[0], 1);
		else if (line[0] == 'R' || line[1] == 'R')
		{
			if (line[0] == 'P' || line[1] == 'P')
				write(output, "P", 1);
			else
				write(output, "R", 1);
		}
		else
			write(output, "S", 1);
		write(output, "\n", 1);
	}
}