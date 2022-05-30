/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:54:07 by sbars             #+#    #+#             */
/*   Updated: 2021/12/16 16:24:29 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stdlib.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
	else
		return ;
}
