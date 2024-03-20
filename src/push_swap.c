/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:20 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/20 12:06:49 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

//error
void ft_error(void)
{
    printf("Error\n");
    exit(0);
}

//Menú para elegir qué tipo de algoritmo de ordenación debe usar
void which_sort(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_lstsize(*stack_a) == 2) //si tengo 2 números que ya sé que están desordenados
        sort2(stack_a);
    else if (ft_lstsize(*stack_a) == 3) // si tengo 3 números
        sort3(stack_a);
    else if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5) //si tengo 5 o 4 números
        sort5(stack_a, stack_b);
    else //para todos los demás
        radix(stack_a, stack_b);
      print_stack(*stack_a); //*******BORRAR******
}

// llena e inicializa el stack de los argumentos que le he pasado
void fill_stack(int argc, char **argv, t_stack **stack_a) 
{
    int i;
    char **args;
    t_stack *new;
    
    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' '); //los argumentos son strings de cada número divididos por el espacio
    else if (argc < 2) //si me pasan 1 argumento o menos tiene que dar error
        exit(0); //CAMBIAR POR "ERROR"
    else // Hay más de 2 argumentos ".a" "2" "3" "1"
    {
        args = argv; //crear una matriz que combine todos los argumentos
        i = 1; //que empiece en 1 para que no cuente como argumento el .a
    }
    while (args[i])
    {
        new = ft_lstnew(ft_atoi(args[i])); // Convertir la cadena a entero y crear un nuevo nodo
        ft_lstadd_back(stack_a, new); // Agregar el nuevo nodo al final de la pila
        i++;
    }
    ft_add_index_to_stack(stack_a);
    if (argc == 2)
        ft_free_str(argv);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (0);
	check_args(argc, argv);
	stack_a = malloc(sizeof(t_stack *));
	stack_b = malloc(sizeof(t_stack *));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(argc, argv, stack_a);
	if (check_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	which_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}