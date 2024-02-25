/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:29 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/25 13:27:51 by mhiguera         ###   ########.fr       */
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

void pb(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a)
    {
        t_stack *temp;
        
        temp = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = *stack_b;
        *stack_b = temp;
    }
}

void rb(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next) // Verifica que haya al menos dos elementos en la pila B
    {
        t_stack *last;
        
        last = *stack_b;
        while (last->next != NULL) // Encuentra el último elemento de la pila B
            last = last->next;
        last->next = *stack_b; // Conecta el último elemento al primer elemento
        *stack_b = (*stack_b)->next; // Avanza el puntero de la pila B al segundo elemento
        last->next->next = NULL; // El anterior primer elemento ahora es el último, así que su siguiente debe ser NULL
    }
}

void rrb(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next) // Verifica que haya al menos dos elementos en la pila B
    {
        t_stack *current = *stack_b;
        t_stack *prev = NULL;
        while (current->next != NULL) // Encuentra el último elemento de la pila B
        {
            prev = current;
            current = current->next;
        }
        
        prev->next = NULL; // El penúltimo elemento ahora es el último, así que su siguiente debe ser NULL
        current->next = *stack_b; // Conecta el último elemento al primer elemento
        *stack_b = current; // Establece el último elemento como el nuevo primer elemento de la pila B
    }
}