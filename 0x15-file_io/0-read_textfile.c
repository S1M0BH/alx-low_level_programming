#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @file_name: text file being read
 * @nlt: number of letters to be read
 * Return: w- aetual number of bytes read and printed
 *        0 when function fails or file_name is NULL.
 */
ssize_t read_textfile(const char *file_name, size_t nlt)
{
	char *bf;
	ssize_t f;
	ssize_t w;
	ssize_t t;

	f = open(file_name, O_RDONLY);
	if (f == -1)
		return (0);
	bf = malloc(sizeof(char) * nlt);
	t = read(f, bf, nlt);
	w = write(STDOUT_FIlnO, bf, t);

	free(bf);
	close(f);
	return (w);
}
