#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes buffer.
 * @file: file name
 *
 * Return: pointer to buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - close a file discriptor
 * @fd: The file discriptor to be closed.
 */
void close_file(int fd)
{
	int cf;

	cf = close(fd);

	if (cf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file.
 * @argc: num of arguments given to the program.
 * @argv: pointer array to the arguments.
 *
 * Return: 0 on success.
 *
 * error codes: 97 - If the argument count is incorrect
 * 98 - If file_from does not exist or cannot be read
 * 99- If file_to cannot be created or written to
 * 100 - If file_to or file_from cannot be closed
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, bites_read, bites_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	bites_read = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || bites_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bites_written = write(file_to, buffer, bites_read);
		if (file_to == -1 || bites_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		bites_read = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (bites_read > 0);

	free(buffer);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
