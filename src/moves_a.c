/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/24 18:07:50 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//doesnt work, first create swap then call swap with first and second
void sa(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next) // Verifica que haya al menos dos elementos en la pila A
    {
        int temp = ft_atoi((*stack_a)->content); // Guarda el valor del primer elemento en la pila A
        (*stack_a)->content = ft_strdup((*stack_a)->next->content); // Copia el valor del segundo elemento al primero
        (*stack_a)->next->content = ft_itoa(temp); // Coloca el valor guardado en el segundo elemento
    }
    print_stack(*stack_a); //comprobación
}

void pa(void);

void ra(void);

void rra(void);