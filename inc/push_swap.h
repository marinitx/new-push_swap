/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:26:27 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/12 15:11:02 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_stack
{
    char *content;
    struct s_stack *next;
} t_stack;

t_stack	*ft_lstnew2(void *content);
void	ft_lstadd_back2(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast2(t_stack *lst);
void check_args(int argc, char **argv);
void check_num(char *num);
void check_dup(int num, char **args, int i);

#endif