/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/18 20:02:41 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//doesnt work, first create swap then call swap with first and second
void sa(t_stack *stack_a)
{
    while (stack_a)
    {
        printf("antes: %s\n", stack_a->content);
        stack_a = stack_a->next;
    }
    swap(stack_a->content, stack_a->next->content);
    while (stack_a)
    {
        printf("después: %s\n", stack_a->content);
        stack_a = stack_a->next;
    }
}

void pa(void);

void ra(void);

void rra(void);

void swap(int *first, int *second)
{
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}