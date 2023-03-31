#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void	winner(char one, char two, int output)
{
	if (one == two)
		write(output, &one, 1);
	else if (one == 'R' || two == 'R')
	{
		if (one == 'P' || two == 'P')
			write(output, "P", 1);
		else
			write(output, "R", 1);
	}
	else
		write(output, "S", 1);
}

int	main(void)
{
	char	*line;
	FILE *fd = fopen("input_winner", "r");
	size_t	i = 0;

	line = NULL;
	getline(&line, &i, fd);
	int	loops = atoi(line);
	int file = open("first_round", O_CREAT | O_RDWR, 0777);
	close(file);
	file = open("second_round", O_CREAT | O_RDWR, 0777);
	close(file);
	int output = open("first_round", O_WRONLY, 0777);
	for(int q = 0; 1; q++)
	{
		for (int j = 0; getline(&line, &i, fd) != -1; j++)
		{
			if (line[1] == '\n')
				return 1;
			for(int k = 0; line[k] != '\n' && line[k] != '\0'; k = k + 2)
			{
				winner(line[k], line[k + 1], output);
			}
			write(output, "\n", 1);
		}
		close(output);
		fclose(fd);
		if (q % 2 == 0)
		{
			fd = fopen("first_round", "r");
			output = open("second_round", O_TRUNC | O_WRONLY, 0777);
		}
		else
		{
			fd = fopen("second_round", "r");
			output = open("first_round", O_TRUNC | O_WRONLY, 0777);
		}
	}
}