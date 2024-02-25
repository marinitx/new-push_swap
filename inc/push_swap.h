/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:26:27 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/25 19:48:30 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_stack
{
    char *content;
    struct s_stack *next;
} t_stack;

t_stack *ft_lstnew2(int content);
void	ft_lstadd_back2(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast2(t_stack *lst);
void check_args(int argc, char **argv);
void check_num(char *num);
void check_dup(int num, char **args, int i);
int	ft_lstsize2(t_stack *lst);
void sa(t_stack **stack_a);
void ss(t_stack **stack_a, t_stack **stack_b);
void sb(t_stack **stack_b);
void print_stack(t_stack *stack);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void sort2(t_stack **stack_a);
void sort3(t_stack **stack_a);
void sort4(t_stack **stack_a, t_stack **stack_b);
void sort5(t_stack **stack_a, t_stack **stack_b);

#endif