/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:29 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/23 10:23:41 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sb(t_stack **stack_b)
{
	int	aux;

	if (*stack_b && (*stack_b)->next)
	{
		aux = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = aux;
	}
	ft_printf("sb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_a)
	{
		aux = *stack_a;
		*stack_a = (*stack_a)->next;
		aux->next = *stack_b;
		*stack_b = aux;
	}
	ft_printf("pb\n");
}

void	rb(t_stack **stack_b)
{
	t_stack	*last;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next != NULL)
			last = last->next;
		last->next = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next->next = NULL;
	}
	ft_printf("rb\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*prev;

	if (*stack_b && (*stack_b)->next)
	{
		current = *stack_b;
		prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack_b;
		*stack_b = current;
	}
	ft_printf("rrb\n");
}
