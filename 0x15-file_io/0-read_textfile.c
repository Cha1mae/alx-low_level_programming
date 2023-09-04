#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: the text file to be read
 * @letters: the max number of letters to be read
 * Return: number of bytes read and printed
 *        0 if the function fails or the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_discriptor;
	ssize_t bites_num;
	ssize_t bites_read;

	file_discriptor = open(filename, O_RDONLY);
	if (file_discriptor == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	bites_read = read(file_discriptor, buffer, letters);
	bites_num = write(STDOUT_FILENO, buffer, bites_read);

	free(buffer);
	close(file_discriptor);
	return (bites_num);
}
