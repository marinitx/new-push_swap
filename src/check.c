/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:37 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/12 16:57:37 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

//Comprueba que no estén los números duplicados
void check_dup(int num, char **args, int i)
{
    i++;
    printf("Esto es num: %d y esto es atoi: %d\n", num, ft_atoi(args[i]));
    while (args[i])
    {
        if (num == ft_atoi(args[i]))
        {
            printf("error\n");
            exit(0);
        }
        i++;    
    }
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

    if (argc == 2)
        args = ft_split(*argv, ' '); //los argumentos son strings de cada número divididos por el espacio
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
        check_dup(tmp, args, i); //si algún número está duplicado.
        i++;
    }
}