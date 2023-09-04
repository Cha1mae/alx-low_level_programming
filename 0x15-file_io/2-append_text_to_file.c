#include "main.h"

/**
 * append_text_to_file - this appends a text at the end of a file.
 * @filename: the name of the file to append the text to.
 * @text_content: The string to append to the file.
 *
 * Return: If this fails or filename is NULL - -1.
 *         If file not exist and the user lacks permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_discriptor, bites_num, lenght = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenght = 0; text_content[lenght];)
			lenght++;
	}

	file_discriptor = open(filename, O_WRONLY | O_APPEND);
	bites_num = write(file_discriptor, text_content, lenght);

	if (file_discriptor == -1 || bites_num == -1)
		return (-1);

	close(file_discriptor);

	return (1);
}
