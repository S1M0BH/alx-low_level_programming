#include "main.h"

/**
 * create_file - Creates a file.
 * @file_name: A pointer to the name of the file to create.
 * @txt_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *file_name, char *txt_content)
{
	int fl, wt, ln = 0;

	if (file_name == NULL)
		return (-1);

	if (txt_content != NULL)
	{
		for (ln = 0; txt_content[ln];)
			ln++;
	}

	fl = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wt = write(fl, txt_content, ln);

	if (fl == -1 || wt == -1)
		return (-1);

	close(fl);

	return (1);
}
