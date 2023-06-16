#include "lists.h"

/**
 * print_dlistint =>Prints all the elements of dlistint_t list.
 * @h: Head_List.
 * Return : Number Nodes.
 */

size_t print_dlistint(const dlistint_t *h)
{
	int i;

	if (h == NULL)
		return (0);
	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	} return (i);
}
