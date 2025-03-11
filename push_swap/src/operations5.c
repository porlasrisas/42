#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (b->size < 1)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	b->size--;
	ft_lstadd_front(&a->top, tmp);
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (a->size < 1)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	a->size--;
	ft_lstadd_front(&b->top, tmp);
	b->size++;
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}
