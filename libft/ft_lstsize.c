/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:37:43 by mhiguera          #+#    #+#             */
/*   Updated: 2024/02/16 12:45:47 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
 * Creo un "strlen" de nodos. Para eso, con un contador que se va sumando en 
 * el while, cuento la cantidad de nodos. La lista irá avanzando con el puntero
 * a "next" que se quedará guardada como nueva posición en la lista.
*/
