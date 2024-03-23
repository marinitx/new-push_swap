/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:20 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/23 10:27:19 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// función de error
void	ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

// menú para elegir qué tipo de algoritmo de ordenación debe usar
void	which_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort2(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5)
		sort5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

// llena e inicializa el stack de los argumentos que le he pasado
void	fill_stack(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**args;
	t_stack	*new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else if (argc < 2)
		ft_error();
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
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
