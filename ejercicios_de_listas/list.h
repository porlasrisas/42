#ifndef LIST_H
    # define LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;

#endif