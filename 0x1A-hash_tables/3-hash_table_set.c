#include "hash_tables.h"

/**
 * hash_table_set ->> Add or update an item in a hash table.
 * @ht: pointer to hash table.
 * @key: Key to be added - cannot be an empty str.
 * @value: The value associated with the key.
 * Return: Depend Condition
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_nd = NULL, *tp = NULL;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tp = ht->array[index];
	while (tp != NULL)
	{
		if (strcmp(tp->key, key) == 0)
		{
			free(tp->value);
			tp->value = strdup(value);
			if (tp->value == NULL)
				return (0);
			return (1);
		}
		tp = tp->next;
	} new_nd = malloc(sizeof(hash_node_t));
	if (new_nd == NULL)
		return (0);
	new_nd->key = strdup(key);
	new_nd->value = strdup(value);
	if (new_nd->key == NULL || new_nd->value == NULL)
	{
		free(new_nd->key);
		free(new_nd->value);
		free(new_nd);
		return (0);
	} new_nd->next = ht->array[index];
	ht->array[index] = new_nd;
	return (1);
}
