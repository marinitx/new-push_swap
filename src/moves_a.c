/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/20 13:50:04 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// swap a: intercambia el primero por el segundo del stack A
void sa(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next) // Verifica que haya al menos dos elementos en la pila A
    {
        int aux;
        
        aux = (*stack_a)->content; // Guarda el valor del primer elemento en la pila A
        (*stack_a)->content = (*stack_a)->next->content; // Copia el valor del segundo elemento al primero
        (*stack_a)->next->content = aux; // Coloca el valor guardado en el segundo elemento
    }
    ft_printf("sa\n");
}

// push a: manda el primer número del stack A a arriba del stack B
void pa(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_b) // Verifica que la pila B no esté vacía
    {
        t_stack *aux;
        
        aux = *stack_b; // Guarda el primer elemento de la pila B
        *stack_b = (*stack_b)->next; // Avanza el puntero de la pila B al siguiente elemento
        aux->next = *stack_a; // Asigna el resto de la pila A como siguiente elemento del primer elemento de la pila B
        *stack_a = aux; // Establece el primer elemento de la pila B como el nuevo primer elemento de la pila A
    }
    ft_printf("pa\n");
}

// rotate a: el primer número pasa a ser el último (o todos suben una posición hacia arriba)
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
    ft_printf("ra\n");
}

// reverse rotate a: el último nodo pasa a ser el primero (o todos bajan una posición)
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
    ft_printf("rra\n");
}