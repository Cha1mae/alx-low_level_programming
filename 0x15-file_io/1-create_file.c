#include "main.h"

/**
 * create_file - Creates a file nd write content in it
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_discriptor, bites_num, lenght = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenght = 0; text_content[lenght];)
			lenght++;
	}

	file_discriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bites_num = write(file_discriptor, text_content, lenght);

	if (file_discriptor == -1 || bites_num == -1)
		return (-1);

	close(file_discriptor);

	return (1);
}
