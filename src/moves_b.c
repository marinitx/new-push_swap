/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:29 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/24 16:59:49 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sb(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next) // Verifica que haya al menos dos elementos en la pila B
    {
        int temp = ft_atoi((*stack_b)->content); // Guarda el valor del primer elemento en la pila B
        (*stack_b)->content = ft_strdup((*stack_b)->next->content); // Copia el valor del segundo elemento al primero
        (*stack_b)->next->content = ft_itoa(temp); // Coloca el valor guardado en el segundo elemento
    }
}

void pb(void);

void rb(void);

void rrb(void);