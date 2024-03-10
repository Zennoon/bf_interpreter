#include "bf.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to return the length of
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len = 0;

	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strcat - concatenates two strings in a new allocated memory
 * @s1: first of the strings to concatenate
 * @s2: second of the strings to concatenate
 *
 * Return: pointer to the memory area holding the concatenation
 */
char *_strcat(char *s1, char *s2)
{
	int len1 = _strlen(s1), len2 = _strlen(s2), i = 0;
	char *ptr1 = s1, *ptr2 =s2;
	char *cat = malloc(sizeof(char) * (len1 + len2 + 1));

	while (s1 && *s1)
	{
		cat[i] = *s1;
		i++;
		s1++;
	}
	while (s2 && *s2)
	{
		cat[i] = *s2;
		i++;
		s2++;
	}
	cat[i] = '\0';
	free(ptr1);
	free(ptr2);
	return (cat);
}

/**
 * read_file - reads the contents of a file whose name is given
 * @filename: name of the file to be read
 *
 * Return: contents of the file as a string if it exists and is readable
 */
char *read_file(char *filename)
{
	int fp = open(filename, O_RDONLY);
	char *tmp_buffer, *buffer = NULL;
	size_t bytes_read = 1024;

	if (fp < 0)
	{
		printf("File can't be found");
		exit(EXIT_FAILURE);
	}
	while (bytes_read == 1024)
	{
		tmp_buffer = malloc(sizeof(char) * 1025);
		bytes_read = read(fp, tmp_buffer, 1024);
		tmp_buffer[bytes_read] = '\0';
		buffer = _strcat(buffer, tmp_buffer);
	}
	close(fp);
	return (buffer);
}
