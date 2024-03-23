/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:48:18 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/23 20:04:46 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->content;
	while (stack != NULL)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
