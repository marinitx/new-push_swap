/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:20 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/18 21:34:50 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void which_sort(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_lstsize2(*stack_a) == 2) //si tengo 2 números que ya sé que están desordenados
        sort2(stack_a);
    else if (ft_lstsize2(*stack_a) == 3) // si tengo 3 números
        sort3(stack_a);
    else if (ft_lstsize2(*stack_a) == 4 || ft_lstsize2(*stack_a) == 5) //si tengo 5 o 4 números
        sort5(stack_a, stack_b);
    else //para todos los demás
        radix(stack_a, stack_b);
      print_stack(*stack_a);
}


void fill_stack(int argc, char **argv, t_stack **stack_a) 
{
    int i;
    char **args;
    t_stack *new;
    
    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' '); //los argumentos son strings de cada número divididos por el espacio
    else if (argc < 2) //si me pasan 1 argumento o menos tiene que dar error
        exit(0);
    else // Hay más de 2 argumentos ".a" "2" "3" "1"
    {
        args = argv; //crear una matriz que combine todos los argumentos
        i = 1; //que empiece en 1 para que no cuente como argumento el .a
    }
    while (args[i])
    {
        new = ft_lstnew2(atoi(args[i])); // Convertir la cadena a entero y crear un nuevo nodo
        ft_lstadd_back2(stack_a, new); // Agregar el nuevo nodo al final de la pila
        i++;
    }
}
//El stack está ya ordenado? el anterior es menor que el actual?
int check_sorted(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
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
    fill_stack(argc, argv, &stack_a);
    tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
    check_sorted(&stack_a); //miro si ya está ordenado de por si
    which_sort(&stack_a, &stack_b);
    ft_free_stack(&stack_a);
}
