/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:07:53 by adandres          #+#    #+#             */
/*   Updated: 2018/04/21 14:24:26 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list		*list;
	int			i;

	i = 2;
	if (ac == 1)
		return (NULL);
	list = ft_lstnew(av[1], ft_strlen(av[1]));
	while (i < ac)
	{
		list = ft_add_link(list, av[i], ft_strlen(av[i]));
		i++;
	}
	return (list);
}
