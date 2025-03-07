#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	// Asignamos a tmp la cabeza de la lista.
	tmp = *lst;
	// Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	// Recorremos la lista hasta llegar al último nodo (donde tmp->next es NULL).
	while (tmp->next)
		tmp = tmp->next;
	// Se añade el nuevo nodo al final de la lista.
	tmp->next = new;
}
