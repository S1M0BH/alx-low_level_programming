#include "lists.h"

/**
 * get_dnodeint_at_index =>Returns the nth node of dlistint_t linked list.
 * @head: Head_List.
 * @index: Index_Node.
 * Return : Node.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *a;

	if (head == NULL)
		return (NULL);
	a = head;
	for (i = 0; i < index; i++)
	{
		if (a == NULL)
			return (NULL);
		a = a->next;
	}
	return (a);
}
