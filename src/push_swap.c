/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:20 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/12 18:32:51 by mhiguera         ###   ########.fr       */
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
//El stack está ya ordenado? NO FUNCIONAAAAAAAAAAAA
void check_sorted(t_stack **stack_a)
{
    int prev;
    int i;
    int sorted;

    prev = 0;
    i = 1;
    sorted = 1; // 0 is sorted, 1 is not sorted
    printf("valor de stack_a[i]: %s\n", (char *)stack_a[prev]);
    while (stack_a->next)
    {
        if (stack_a[prev] < stack_a[i])
        {
            printf("sorted\n");
            i++;
            prev++;
            sorted = 0;
        }
        else
            sorted = 1;
    }
    //el anterior es menor que el actual?
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
    check_args(argc, argv); //primero comprueba que los argumentos sean números y no estén repetidos
    stack_a = NULL;
    stack_b = NULL;
    printf("%s\n", "he llegado");
    fill_stack(argc, argv, &stack_a);
    tmp = stack_a;
    while (tmp)
    {
        printf("%s\n", tmp->content);
        tmp = tmp->next;
    }
    check_sorted(&stack_a);
}