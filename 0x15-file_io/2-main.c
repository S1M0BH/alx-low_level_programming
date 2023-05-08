#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ae, char **av)
{
    int rs;

    if (ae != 3)
    {
	dprintf(2, "Usage: %s filename text\n", av[0]);
	exit(1);
    }
    rs = append_text_to_file(av[1], av[2]);
    printf("-> %i)\n", rs);
    return (0);
}
