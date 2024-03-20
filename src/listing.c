/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:13:13 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/20 12:04:02 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// devuelve el último nodo de la lista
t_stack	*ft_lstlast(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

// crea nuevos nodos y guarda memoria
t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

// añade un nodo al principio de la lista
void	ft_lstfront(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

// añade un nodo al final de la lista
void	ft_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp;

	if (!new_node)
		return ;
	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		tmp -> next = new_node;
	}
	else
		*stack = new_node;
}

// devuelve el tamaño de la lista
int	ft_lstsize(t_stack *head)
{
	int	stack_size;

	stack_size = 0;
	while (head)
	{
		stack_size++;
		head = head->next;
	}
	return (stack_size);
}