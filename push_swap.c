#include "push_swap.h"

int main(int argc, char **argv)
{
    char **args;
    int i;
    t_list **stack_a;
    t_list **stack_b;

    if (argc < 2)
        exit(0);
    else
        check_args(argc, argv); //primero comprueba que los argumentos sean números y no estén repetidos
        stack_a = ft_calloc();
        stack_b = ft_calloc();
}