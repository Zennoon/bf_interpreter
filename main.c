#include "bf.h"

#define ARR_SIZE 300

/**
 * looper - Loops (executes some commands) until current index has a value of 0.
 * @command_ptr: Pointer to the current command (character)
 * @array: The array being operated on
 * @idx: Pointer to the current index of the array
 *
 * Return: Pointer to the command immediately after the loop terminates
 */
char *looper(char *command_ptr, int *array, int *idx)
{
	int nested = 0;
	size_t i = 0;
	char *looped_commands = malloc(sizeof(char));

	while (command_ptr && (*command_ptr != ']' || nested != 0))
	{
		if (*command_ptr == '[')
			nested++;
		else if (*command_ptr == ']')
			nested--;
		looped_commands[i] = *command_ptr;
		i++;
		looped_commands = realloc(looped_commands, i + 1);
		command_ptr++;
	}
	looped_commands[i] = '\0';
	while (array[*idx] != 0)
		execute_commands(looped_commands, array, idx);
	free(looped_commands);
	return (command_ptr);
}

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
{
	while (commands && *commands)
	{
		switch (*commands)
		{
		case '>':
			*idx += 1;
			break;
		case '<':
			*idx -= 1;
			break;
		case '+':
			array[*idx] += 1;
			break;
		case '-':
			array[*idx] -= 1;
			break;
		case '.':
			printf("%c", array[*idx]);
			break;
		case ',':
			scanf("%d", &(array[*idx]));
			break;
		case '[':
			commands++;
			commands = looper(commands, array, idx);
			if (!commands)
				commands--;
			break;
		}
		commands++;
	}
}

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
	int array[ARR_SIZE], idx = 0, i;

	if (argc < 2)
	{
		printf("Usage: ./bf_interpreter filename\n");
		exit(EXIT_FAILURE);
	}
	for (idx = 0; idx < ARR_SIZE; idx++)
		array[idx] = 0;
	idx = 0;
	commands = read_file(argv[1]);
	execute_commands(commands, array, &idx);
	for (i = 0; i < ARR_SIZE; i++)
		printf("%d ", array[i]);
	free(commands);
	return (EXIT_SUCCESS);
}
