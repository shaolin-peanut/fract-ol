/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:14:20 by sbars             #+#    #+#             */
/*   Updated: 2021/12/20 14:34:38 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*iterator;

	if (!lst)
		return (0);
	count = 0;
	iterator = lst;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
