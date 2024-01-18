#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom
 * @head: Stack head
 * @counter: Line number (unused)
 *
 * Return: No return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		/* Stack is empty or has only one element, no rotation needed */
		return;
	}

	stack_t *current = *head;
	stack_t *last = *head;

	/* Traverse to find the last node */
	while (last->next)
	{
		last = last->next;
	}

	/* Perform rotation */
	last->next = *head;
	(*head)->prev = last;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->next = NULL;
}
