/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:48:18 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/25 19:47:18 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"

/* void    ft_error(void)
{
    ft_printf("%s", "Hola");
    exit(1);
}
*/

void ft_lstadd_back2(t_stack **lst, t_stack *new) 
{
    t_stack *temp;

    if (*lst == NULL)
        *lst = new;
    else 
	{
        temp = *lst;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

t_stack *ft_lstnew2(int content) 
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return NULL;
    new->content = content;
    new->next = NULL;
    return new;
}

t_stack	*ft_lstlast2(t_stack *lst)
{
	while ((lst != NULL) && (lst->next != NULL))
		lst = lst->next;
	return (lst);
}

void print_stack(t_stack *stack)
{
    printf("Contenido de la pila:\n");
    while (stack)
    {
        printf("%s\n", stack->content);
        stack = stack->next;
    }
}

int ft_lstsize2(t_stack *lst) 
{
    int count;
    t_stack *temp;

    count = 0;
    temp = lst;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
