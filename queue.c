#include "monty.h"

/**
 * f_queue - Sets the behavior to queue (FIFO)
 * @head: Stack head
 * @counter: Line number (unused)
 *
 * Return: No return
 */
void f_queue(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	(void)head;
	bus.lifi = 1; /* Set the queue flag */
}

/**
 * add_queue - Adds a node to the tail of the stack
 * @head: Pointer to the head of the stack
 * @n: Value to be added to the node
 *
 * Return: No return
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		/* If the stack is empty, set the new node as the head */
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Add the new node to the tail */
		aux->next = new_node;
		new_node->prev = aux;
	}
}
