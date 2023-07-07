#include "hash_tables.h"

/**
 * hash_table_get ->> The value associated with the key.
 * @ht: pointer to hash table.
 * @key: key to get value.
 * Return: Depend Condition.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *tp = NULL;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tp = ht->array[index];
	while (tp != NULL)kk
	{
		if (strcmp(tp->key, key) == 0)
			return (tp->value);
		tp = tp->next;
	} return (NULL);
}
