/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:12:49 by sbars             #+#    #+#             */
/*   Updated: 2021/12/20 14:34:27 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (node != NULL)
	{
		if (content)
			node->content = content;
		else
			node->content = NULL;
		node->next = NULL;
	}
	return (node);
}
