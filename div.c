#include "monty.h"

/**
 * f_div - Divides the second element from the top by the top element
 * @head: Stack head
 * @counter: Line number
 *
 * Return: No return
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, result;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = h->next->n / h->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
