/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:20 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/16 13:53:00 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void fill_stack(int argc, char **argv, t_stack **stack_a)
{
    int i;
    char **args;
    t_stack *new;
    
    
    i = 1;
    if (argc == 2)
        args = ft_split(*argv, ' '); //los argumentos son strings de cada número divididos por el espacio
    else if (argc < 2) //si me pasan 1 argumento o menos tiene que dar error
        exit(0);
    else // Hay más de 2 argumentos ".a" "2" "3" "1"
    {
        args = argv; //crear una matriz que combine todos los argumentos
        i = 1; //que empiece en 1 para que no cuente como argumento el .a
    }
    // ./push_swap "9 4 7 1"
        printf("%s\n", "hola");
        printf("argc es %d\n", argc);
    while (args[i])
    {
        printf("argumentos: %s\n", args[i]);
        new = ft_lstnew2(args[i]);
        printf("%s\n", new->content);
        ft_lstadd_back2(stack_a, new);
        i++;
        //voy a ir creando los nodos con lstnew y luego añadiendolos al final del stack a con lstaddback
    }
}
//El stack está ya ordenado? el anterior es menor que el actual?
void check_sorted(t_stack **stack_a)
{
    int i;
    int sorted;
    t_stack *current = *stack_a;

    i = 1;
    sorted = 0; // 0 means sorted, 1 means not sorted
    while (current->next != NULL)
    {
        printf("Contenido en current: %s\n", current->content);
        printf("Contenido en siguiente: %s\n", current->next->content);
        if (ft_atoi(current->content) > ft_atoi(current->next->content)) //si (pasando a int) el número que contiene content es mayor al número que contiene el contenido del siguiente argumento
        {
            printf("Entro\n");
            sorted = 1; //this list is not sorted
            break;
        }
        current = current->next;
    }
    if (sorted == 0)
        printf("The stack is sorted.\n");
    else
        printf("The stack is not sorted.\n");
}

int main(int argc, char **argv)
{
    char **args;
    int i;
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *tmp;

    if (argc < 2)
        exit(0);
    printf("%s\n", "he llegado");
    check_args(argc, argv); //primero comprueba que los argumentos sean números y no estén repetidos
    stack_a = NULL;
    stack_b = NULL;
    fill_stack(argc, argv, &stack_a);
    tmp = stack_a;
    while (tmp)
    {
        printf("%s\n", tmp->content);
        tmp = tmp->next;
    }
    check_sorted(&stack_a); //miro si ya está ordenado de por si
    
}