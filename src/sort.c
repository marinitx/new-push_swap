/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:25 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/17 12:56:23 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort2(t_stack **stack_a)
{
    sa(stack_a);
}

void sort3(t_stack **stack_a)
{
    int min;
    int max;
    
    min = get_min(*stack_a);
    max = get_max(*stack_a);
    
    if ((*stack_a)->content == max && (*stack_a)->next->content != min) // 3 2 1
    {
        ra(stack_a); // 2 1 3
        sa(stack_a); // 1 2 3
    }
    else if ((*stack_a)->content == min && (*stack_a)->next->content == max) //1 3 2
    {
        sa(stack_a); // 3 1 2
        ra(stack_a); // 1 2 3
    }
    else if ((*stack_a)->content == max && (*stack_a)->next->content == min) // 3 1 2
        ra(stack_a); // 1 2 3
    else if ((*stack_a)->next->content == min && ft_lstlast2(*stack_a)->content == max) // 2 1 3
        sa(stack_a); // 1 2 3
    else if ((*stack_a)->next->content == max && ft_lstlast2(*stack_a)->content == min) // 2 3 1
        rra(stack_a); // 1 2 3
}

void sort5(t_stack **stack_a, t_stack **stack_b)
{   
    while (ft_lstsize2(*stack_a) > 3)
    {
        if ((*stack_a)->content == get_min(*stack_a))
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }
    sort3(stack_a);
    while (*stack_b)
    {
        pa(stack_a,stack_b);
    }
    return ;
}