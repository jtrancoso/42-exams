#include "get_next_line.h"

int	main(void)
{
	int r;
	char *line;

	while ((r = get_next_line(&line) > 0))
	{
		printf("%s\n", line);
	}
	printf("%s\n", line);

}