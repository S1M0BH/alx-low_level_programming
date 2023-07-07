#include "hash_tables.h"

/**
 * shash_table_create ->> creates a sorted hash table.
 * @size: size of hash table.
 * Return: Depend Condition.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table_create;
	unsigned long int i;

	new_table_create = malloc(sizeof(shash_table_t));
	if (new_table_create == NULL)
		return (NULL);
	new_table_create->size = size;
	new_table_create->shead = NULL;
	new_table_create->stail = NULL;
	new_table_create->array = malloc(sizeof(shash_node_t) * size);
	if (new_table_create->array == NULL)
	{
		free(new_table_create);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		new_table_create->array[i] = NULL;
	} return (new_table_create);
}

/**
 * make_shash_node ->> Creates a node for the sorted hash table.
 * @key: data key.
 * @value: The data to be stored.
 * Return: case depended.
 */

shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	} node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	} node->next = node->snext = node->sprev = NULL;
	return (node);
}

/**
 * add_to_sorted_list ->> Adding a node to an ordered
 * linked list (as per ASCII key).
 * @table: Classified hash table.
 * @node: The node to be added.
 */

void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *next;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	} next = table->shead;
	while (next != NULL)
	{
		if (strcmp(node->key, next->key) < 0)
		{
			node->snext = next;
			node->sprev = next->sprev;
			next->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		} next = next->snext;
	} node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set ->> Assigns a key to a value in the hash table.
 * @ht: Classified hash table.
 * @key: data key.
 * @value: data add.
 * Return: case depended.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	char *new_value_te;
	shash_node_t *node, *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	next = ht->array[i];
	while (next != NULL)
	{
		if (strcmp(next->key, key) == 0)
		{
			new_value_te = strdup(value);
			if (new_value_te == NULL)
				return (0);
			free(next->value);
			next->value = new_value_te;
			return (1);
		} next = next->next;
	} node = make_shash_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[i];
	ht->array[i] = node;
	add_to_sorted_list(ht, node);
	return (1);
}

/**
 * shash_table_get ->> retrieve a value from the hash table.
 * @ht: the hash table.
 * @key: data key.
 * Return: case depended.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int i;
	shash_node_t *m;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	m = ht->array[i];
	while (m != NULL)
	{
		if (strcmp(m->key, key) == 0)
			return (m->value);
		m = m->next;
	} return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table.
 * @ht: print hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->snext;
	} printf("}\n");
}

/**
 * shash_table_print_rev ->> prints a sorted hash table in reverse.
 * @ht: print hash table.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *next;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	next = ht->stail;
	while (next != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", next->key, next->value);
		flag = 1;
		next = next->sprev;
	} printf("}\n");
}

/**
 * shash_table_delete ->> deletes a sorted hash table
 * @ht: hash table to delete.
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	} free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
