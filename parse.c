#include "monty.h"
/**
 *parse -tokenizes monty  file input and calls corresponding opcode
 *function
 *Return: void
 */
void parse(void)
{
	int i = 0;
	char *token;

	while ((mon.line = getline(&mon.buff, &mon.len, mon.file)) != -1)
	{
		/*initialize the mon.args(2-dimensional array) to NULL*/
		while (mon.args[i])
		{
			mon.args[i] = NULL;
			i++;
		}
		i = 0;
		mon.buff[strlen(mon.buff) - 1] = '\0';
		token = strtok(mon.buff, " \t\n");
		if (!token || token[0] == '#' || token[0] == '\0')
		{
			mon.line_number++;
			continue;
		}
		for (i = 0; token != NULL; i++)
		{
			mon.args[i] = token;
			token = strtok(NULL, " ");
			if (i > 2)
				break;
		}
		ops();
		mon.line_number++;
	}
}
