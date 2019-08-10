/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:36:50 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 16:36:56 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return ((int)(c - 32));
	return ((int)c);
}
