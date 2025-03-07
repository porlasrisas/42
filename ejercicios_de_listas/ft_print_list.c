#include "list.h"
void ft_print_list(t_list *lst)
{
    while(lst)
    {
        printf("%d\n", (int)(long)lst->content);
        lst = lst->next;
    }
}
