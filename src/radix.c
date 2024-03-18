/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:40:53 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/18 21:57:48 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_lstsize2(*stack_a);
	while (!check_sorted(stack_a)) //falla esto porque nunca se ordena y nunca se ordena porque la i avanza
	{
		print_stack(*stack_a);
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1) // si i = 0 entonces que rote los números que no tengan 0 como último número
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		printf("%d\n", i);
		while (ft_lstsize2(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}