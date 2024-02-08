/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:37 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/08 19:38:09 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

#include "../inc/push_swap.h"

//Comprueba que no estén los números duplicados
int check_dup(int num, char **args, int i)
{
    int i;

    i = 0;
    while (args)
    {
        if (num == ft_atoi(args[i]));
    }
}

//Comprueba que los argumentos sean números y no otra cosa
int check_num(char *num)
{
    int i;

    i = 0;
    while (num)
    {
        if (!(num[i] > '9' & num[i] < '0'))
               ft_error();
        else
            return (0);
    }
}

void check_args(int argc, char **argv)
{
    char **args;
    int i;
    int tmp;

    if (argc == 2)
        args = ft_split(argv, ' '); //los argumentos son strings de cada número divididos por el espacio
    else if (argc < 2) //si me pasan 1 argumento o menos tiene que dar error
        ft_error();
    else // Hay más de 2 argumentos ".a" "2" "3" "1"
    {
        args = argv; //crear una matriz que combine todos los argumentos
        i = 1; //que empiece en 1 para que no cuente como argumento el .a
    }
    while (args[i])
    {
        check_num(args[i]); //si no es un número algún argumento
        tmp = ft_atoi(args[i]); // ahora todos son números char, pásamelo a ints
        check_dup(tmp, args, i); //si algún número está duplicado
        if (tmp < -2147483647 || tmp > 2147483647)
            ft_error();
    }


}
*/

