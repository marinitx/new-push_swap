/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/23 10:19:28 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// swap a: intercambia el primero por el segundo del stack A
void	sa(t_stack **stack_a)
{
	int	aux;

	if (*stack_a && (*stack_a)->next)
	{
		aux = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = aux;
	}
	ft_printf("sa\n");
}

// push a: manda el primer número del stack B a arriba del stack A
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_b)
	{
		aux = *stack_b;
		*stack_b = (*stack_b)->next;
		aux->next = *stack_a;
		*stack_a = aux;
	}
	ft_printf("pa\n");
}

// rotate a: el primer número pasa a ser el último (o todos suben una posición)
void	ra(t_stack **stack_a)
{
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next != NULL)
			last = last->next;
		last->next = *stack_a;
		*stack_a = (*stack_a)->next;
		last->next->next = NULL;
	}
	ft_printf("ra\n");
}

// reverse rotate a: último nodo pasa a ser primero (o todos bajan una posición)
void	rra(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*prev;

	if (*stack_a && (*stack_a)->next)
	{
		current = *stack_a;
		prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack_a;
		*stack_a = current;
	}
	ft_printf("rra\n");
}
