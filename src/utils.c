/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:48:18 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/17 12:23:44 by mhiguera         ###   ########.fr       */
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
        printf("%d\n", stack->content);
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

int get_min(t_stack *stack) {
    int min = stack->content;
    while (stack != NULL) {
        if (stack->content < min)
            min = stack->content;
        stack = stack->next;
    }
    return min;
}

int get_max(t_stack *stack) {
    int max = stack->content;
    while (stack != NULL) {
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
    }
    return max;
}

