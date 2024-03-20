/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:11:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/20 11:58:41 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_get_next_min(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack_a;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->content
					< min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_add_index_to_stack(t_stack **stack_a)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = ft_get_next_min(stack_a);
	while (head)
	{
		head->index = index++;
		head = ft_get_next_min(stack_a);
	}
}