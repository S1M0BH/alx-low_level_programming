#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_bffer(char *file);
void close_file(int f);

/**
 * create_bffer - Allocates 1024 bytes for a bffer.
 * @file: The name of the file bffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated bffer.
 */
char *create_bffer(char *file)
{
	char *bffer;

	bffer = malloc(sizeof(char) * 1024);

	if (bffer == NULL)
	{
		dprintf(STDERR_FIlnO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bffer);
}

/**
 * close_file - Closes file descriptors.
 * @f: The file descriptor to be closed.
 */
void close_file(int f)
{
	int c;

	c = close(f);

	if (c == -1)
	{
		dprintf(STDERR_FIlnO, "Error: Can't close f %d\n", f);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *bffer;

	if (argc != 3)
	{
		dprintf(STDERR_FIlnO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bffer = create_bffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, bffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FIlnO,
				"Error: Can't read from file %s\n", argv[1]);
			free(bffer);
			exit(98);
		}

		w = write(to, bffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FIlnO,
				"Error: Can't write to %s\n", argv[2]);
			free(bffer);
			exit(99);
		}

		r = read(from, bffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(bffer);
	close_file(from);
	close_file(to);

	return (0);
}
