/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:25 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/25 19:37:29 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort2(t_stack **stack_a)
{
    sa(stack_a);
}

void sort3(t_stack **stack_a)
{
    if (((*stack_a)->content) > ((*stack_a)->next->content))
        sa(stack_a);
    else if (((*stack_a)->content) > ((*stack_a)->next->next->content))
        ra(stack_a);
    else if ((*stack_a)->next->content > (*stack_a)->next->next->content)
    {
        sa(stack_a);
        rra(stack_a);
    }
    print_stack(*stack_a); //comprobación
}

void sort4(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_a, stack_b);
    sort3(stack_a);
    pa(stack_a, stack_b);
}

void sort5(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    sort3(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}