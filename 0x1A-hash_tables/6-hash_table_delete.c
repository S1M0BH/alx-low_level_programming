#include "hash_tables.h"

/**
 * hash_table_delete ->> Deletes a hash table
 * @ht: pointer to Hash Table
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *tp = NULL, *tp2 = NULL;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		tp = ht->array[i];
		while (tp != NULL)
		{
			tp2 = tp->next;
			free(tp->key);
			free(tp->value);
			free(tp);
			tp = tp2;
		}
	} free(ht->array);
	free(ht);
}
