/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:31 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/20 13:50:24 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a); // Realiza el swap en la pila A
    sb(stack_b); // Realiza el swap en la pila B
    ft_printf("ss\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a); // Realiza el rotate en la pila A
    rb(stack_b); // Realiza el rotate en la pila B
    ft_printf("rr\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a); // Realiza el reverse rotate en la pila A
    rrb(stack_b); // Realiza el reverse rotate en la pila B
    ft_printf("rrr\n");
}

