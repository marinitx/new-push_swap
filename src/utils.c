/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:48:18 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/24 18:06:21 by mhiguera         ###   ########.fr       */
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

void	ft_lstadd_back2(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = ft_lstlast2(*(lst));
		node->next = new;
	}
}

t_stack	*ft_lstnew2(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
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

/*
int	ft_lstsize2(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
*/