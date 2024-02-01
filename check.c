#include "push_swap.h"

//Comprueba que no estén los números duplicados
void isdup();

//Comprueba que los argumentos sean números y no otra cosa
void isnum(); 

void check_args(int argc, char **argv)
{
    char **args;
    int i;
    int tmp;

    if (argc == 2)
        args = ft_split(argv, ' '); //los argumentos son strings de cada número divididos por el espacio
    else // Hay más de 2 argumentos ".a" "2" "3" "1"
    {
        args = argv; //crear una matriz que combine todos los argumentos
        i = 1; //que empiece en 1 para que no cuente como argumento el .a
    }
    while (args[i])
    {
        if (!isnum) //si no es un número algún argumento
            exit(0);
        tmp = ft_atoi(args[i]); //todos son números char, pásamelo a ints
        if (!isdup) //si algún número está duplicado
            exit(0);
        if (tmp < -2147483647 || tmp > 2147483647)
            exit(0);
    }


}

