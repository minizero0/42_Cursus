/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:59:45 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/19 17:01:50 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new_list, del);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
