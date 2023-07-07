#include "hash_tables.h"

/**
 * key_index ->> It gives you a key index.
 * @key: key to get an index.
 * @size: The size of the hash table matrix.
 * Return: text.
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int text = hash_djb2(key) % size;

	return (text);
}
