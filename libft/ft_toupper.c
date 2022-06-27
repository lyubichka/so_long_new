/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 05:02:30 by vlyubick          #+#    #+#             */
/*   Updated: 2021/10/02 05:05:18 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}