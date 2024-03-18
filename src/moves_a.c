/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/18 21:44:13 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sa(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next) // Verifica que haya al menos dos elementos en la pila A
    {
        int temp;
        
        temp = (*stack_a)->content; // Guarda el valor del primer elemento en la pila A
        (*stack_a)->content = (*stack_a)->next->content; // Copia el valor del segundo elemento al primero
        (*stack_a)->next->content = temp; // Coloca el valor guardado en el segundo elemento
    }
    printf("sa\n");
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_b) // Verifica que la pila B no esté vacía
    {
        t_stack *temp;
        
        temp = *stack_b; // Guarda el primer elemento de la pila B
        *stack_b = (*stack_b)->next; // Avanza el puntero de la pila B al siguiente elemento
        temp->next = *stack_a; // Asigna el resto de la pila A como siguiente elemento del primer elemento de la pila B
        *stack_a = temp; // Establece el primer elemento de la pila B como el nuevo primer elemento de la pila A
    }
    //printf("pa\n");
}

void ra(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next) // Verifica que haya al menos dos elementos en la pila A
    {
        t_stack *last;
        
        last = *stack_a;
        while (last->next != NULL) // Encuentra el último elemento de la pila A
            last = last->next;
        last->next = *stack_a; // Conecta el último elemento al primer elemento
        *stack_a = (*stack_a)->next; // Avanza el puntero de la pila A al segundo elemento
        last->next->next = NULL; // El anterior primer elemento ahora es el último, así que su siguiente debe ser NULL
    }
    printf("ra\n");
}

void rra(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next) // Verifica que haya al menos dos elementos en la pila A
    {
        t_stack *current;
        t_stack *prev;
        
        current = *stack_a;
        prev = NULL;
        while (current->next != NULL) // Encuentra el último elemento de la pila A
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL; // El penúltimo elemento ahora es el último, así que su siguiente debe ser NULL
        current->next = *stack_a; // Conecta el último elemento al primer elemento
        *stack_a = current; // Establece el último elemento como el nuevo primer elemento de la pila A
    }
    printf("rra\n");
}