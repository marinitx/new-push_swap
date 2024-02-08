/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:20 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:46 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void fill_stack(int argc, char **argv, t_list **stack_a)
{
    int i;
    char **args;
    t_list *new;
    
    
    i = 0;
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
    while (args)
    {
        new = ft_lstnew(args[i]);
        ft_lstadd_back(stack_a, new);
        i++;
        printf("%s", "hola");
        //voy a ir creando los nodos con lstnew y luego añadiendolos al final del stack a con lstaddback
    }
        
}


int main(int argc, char **argv)
{
    char **args;
    int i;
    t_list **stack_a;
    t_list **stack_b;

    if (argc < 2)
        exit(0);
    printf("%s", "he llegado");
    //check_args(argc, argv); //primero comprueba que los argumentos sean números y no estén repetidos
    stack_a = malloc(sizeof(t_list));
    stack_b = malloc(sizeof(t_list));
    stack_a = NULL;
    stack_b = NULL;
    fill_stack(argc, argv, stack_a);    
}