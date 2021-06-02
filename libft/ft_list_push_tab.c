/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:49:39 by adandres          #+#    #+#             */
/*   Updated: 2018/04/21 14:24:34 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_tab(char **av)
{
	t_list		*list;
	int			i;

	i = 1;
	if (!av)
		return (NULL);
	list = ft_lstnew(av[0], ft_strlen(av[0]));
	while (av[i])
	{
		list = ft_add_link(list, av[i], ft_strlen(av[i]));
		i++;
	}
	return (list);
}
