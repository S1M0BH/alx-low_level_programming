#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @file_name: A pointer to the name of the file.
 * @txt_content: The string to add to the end of the file.
 *
 * Return: If the function fails or file_name is NULL - -1.
 *         If the file does not exist the user laeks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *file_name, char *txt_content)
{
	int p, wt, l = 0;

	if (file_name == NULL)
		return (-1);

	if (txt_content != NULL)
	{
		for (l = 0; txt_content[l];)
			l++;
	}

	p = open(file_name, O_WRONLY | O_APPEND);
	wt = write(p, txt_content, l);

	if (p == -1 || wt == -1)
		return (-1);

	close(p);

	return (1);
}
