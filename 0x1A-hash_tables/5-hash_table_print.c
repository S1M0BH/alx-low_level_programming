#include "hash_tables.h"

/**
 * hash_table_print -> Prints a hash table.
 * @ht: A pointer to a printable hash table.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *tp = NULL;
	int c = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tp = ht->array[i];
		while (tp != NULL)
		{
			if (c == 1)
				printf(", ");
			printf("'%s': '%s'", tp->key, tp->value);
			c = 1;
			tp = tp->next;
		}
	} printf("}\n");
}
