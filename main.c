#include "monty.h"
/*global struct*/
/*monty_details mon;*/
#define AGSIZE 10
/**
 *main - main file of the monty interpreter
 *@argc:arguement count
 *@argv:arguement vector
 *Return: 0
 */
int main(int argc, char *argv[])
{
	/*initialization of mon variables*/
	mon.line_number = 1;
	mon.stack_queue = 1;
	mon.file = NULL;
	mon.args = malloc(sizeof(char *) * AGSIZE);
	if (!mon.args)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freer();
		exit(EXIT_FAILURE);
	}
	/*arguement count should be 2*/
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		freer();
		exit(EXIT_FAILURE);
	}
	/*check whether file is accessible*/
	if (access(argv[1], R_OK) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		freer();
		exit(EXIT_FAILURE);
	}
	mon.file = fopen(argv[1], "r");
	if (!mon.file)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freer();
		exit(EXIT_FAILURE);
	}
	parse();
	freer();
	return (EXIT_SUCCESS);
}
