#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void	fill_rest_scissors(int *rocks, int *scissors, int output, int participants)
{
	for(int i = 0; i < participants / 2; i++)
	{
		if (*rocks > (participants / 2) - i)
		{
			write(output, "R", 1);
			write(output, "R", 1);
			(*rocks)--;
			(*rocks)--;
		}
		else if (*rocks == 1)
		{
			write(output, "R", 1);
			(*rocks)--;
		}
		else
		{
			write(output, "S", 1);
			write(output, "R", 1);
			(*rocks)--;
			(*scissors)--;
		}
	}
}

void	fill_first_half(int *rocks, int *papers, int *scissors, int output, int participants)
{
	int	temp_rocks;

	temp_rocks = *rocks;
	*rocks = *rocks - participants / 2 + 1;
	if (*papers == 1 && *rocks > 0)
	{
		*rocks = temp_rocks;
		fill_rest_scissors(rocks, scissors, output, participants);
		write(output, "P", 1);
		(*papers)--;
	}
	else
	{
		for (int i = 1; i < participants / 2; i++)
			write(output, "R", 1);
		write(output, "P", 1);
		(*papers)--;
	}
}

void	fill_fully(int *rocks, int *papers, int output, int participants)
{
	for (int i = 1; i < participants; i++)
		write(output, "R", 1);
	write(output, "P", 1);
	*rocks = *rocks - participants + 1;
	(*papers)--;
}

int	main(void)
{
	char	*line;
	FILE *fd = fopen("input", "r");
	size_t	i = 0;
	int	rocks;
	int	papers;
	int	scissors;
	int	participants;
	int	temp = 0;
	int	temp_participants;

	line = NULL;
	getline(&line, &i, fd);
	int	loops;
	sscanf(line, "%d %d", &loops, &participants);
	int output = open("output", O_CREAT | O_WRONLY, 0777);
	for (int j = 0; j < loops; j++)
	{
		temp_participants = participants;
		temp = 0;
		getline(&line, &i, fd);
		sscanf(line, "%dR %dP %dS", &rocks, &papers, &scissors);
		while (rocks > 2)
		{
			if (rocks == temp_participants - 1)
				fill_fully(&rocks, &papers, output, temp_participants);
			else if (rocks > (temp_participants / 2) - 1)
				fill_first_half(&rocks, &papers, &scissors, output, temp_participants);
			temp_participants = temp_participants / 2;
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