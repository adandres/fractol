/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:21:29 by adandres          #+#    #+#             */
/*   Updated: 2018/12/21 10:44:36 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_add_link(t_list *list, void *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		if (!(tmp->content = malloc(content_size)))
			return (0);
		tmp->content = content;
		tmp->content_size = content_size;
		tmp->next = list;
	}
	return (tmp);
}
