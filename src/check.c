/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:37 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/20 11:40:25 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Comprueba que no estén los números duplicados
void check_dup(int num, char **args, int i)
{
    i++;
    while (args[i] != NULL)
    {
        if (num == ft_atoi(args[i]))
        {
            ft_error();
        }
        i++;    
    }
}

//Comprueba si es un dígito
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//Comprueba que los argumentos sean números y no otra cosa
void check_num(char *num)
{
    int i;

    i = 0;
    if (num[i] == '-')
        i++;
    while (num[i] != '\0' && num[i] != ' ')
    {
        if (!ft_isdigit(num[i]))
            exit(0);
        i++;
    }
}

void check_args(int argc, char **argv)
{
    char **args;
    int i;
    int tmp;

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
        check_num(args[i]); //si no es un número algún argumento
        tmp = ft_atoi(args[i]); // ahora todos son números char, pásamelo a ints
        if (tmp < -2147483647 || tmp > 2147483647)
            exit(0);
        if (args[i + 1] != NULL)
            check_dup(tmp, args, i); //si algún número está duplicado.
        i++;
    }
}

//El stack está ya ordenado? el actual es mayor que el siguiente? 0 es que no está ordenado y 1 que sí está ordenado
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