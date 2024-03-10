#include "bf.h"

#define ARR_SIZE 30000

/**
 * execute_commands - Executes the commands stored in a string
 * @commands: The string containing command/instruction per character
 * @array: The array being operated on
 * @idx: Pointer to the current index of the array at which operations are
 * performed
 *
 * Return: void
 */
void execute_commands(char *commands, int *array, int *idx)

/**
 * main - The entry point of the program
 * @argc: Argument Count
 * @argv: Argument Vector (1D array of the command line arguments)
 *
 * Return: EXIT_SUCCESS on successful termination, EXIT_FAILURE otherwise
 */
int main(int argc, char **argv)
{
	char *commands;
	int array[30000], idx = 0;

	if (argc < 2)
	{
		printf("Usage: ./bf_interpreter filename\n");
		exit(EXIT_FAILURE);
	}
	for (idx = 0; idx < ARR_SIZE; idx++)
		array[idx] = 0;
	commands = read_file(argv[1]);
	execute_commands(commands, array, *idx);
	return (EXIT_SUCCESS);
}
