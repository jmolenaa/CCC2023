#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	FILE *fd = fopen("input", "r");
	size_t	i = 0;
	int	rocks;
	int	papers;
	int	scissors;

	line = NULL;
	getline(&line, &i, fd);
	int	loops = atoi(line);
	int output = open("output", O_CREAT | O_WRONLY, 0777);
	for (int j; j < loops; j++)
	{
		getline(&line, &i, fd);
		sscanf(line, "%dR %dP %dS", &rocks, &papers, &scissors);
		while (rocks > 2)
		{
			write(output, "RRRP", 4);
			rocks = rocks - 3;
			papers--;
		}
		if (rocks == 2)
		{
			if (papers == 1)
			{
				write(output, "RSRP", 4);
				scissors--;
				papers--;
			}
			else
			{
				write(output, "RRPP", 4);
				papers = papers - 2;
			}
			rocks = 0;
		}
		if (rocks == 1)
		{
			write(output, "RP", 2);
			rocks--;
			papers--;
		}
		for(; papers > 0; papers--)
			write(output, "P", 1);
		for(; scissors > 0; scissors--)
			write(output, "S", 1);
		write(output, "\n", 1);
	}
}