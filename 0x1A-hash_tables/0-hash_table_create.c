#include "hash_tables.h"


/**
 * hash_table_create ->> Creates function a hash table
 * @size: Array Size
 * Return: pointer to the new hash table
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_hash_table_created = NULL;
	unsigned long int i = 0;

	new_hash_table_created = malloc(sizeof(hash_table_t));
	if (new_hash_table_created == NULL)
		return (NULL);

	new_hash_table_created->size = size;
	new_hash_table_created->array = malloc(sizeof(hash_node_t *) * size);
	if (new_hash_table_created->array == NULL)
	{
		free(new_hash_table_created);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		new_hash_table_created->array[i] = NULL;
	return (new_hash_table_created);
}
