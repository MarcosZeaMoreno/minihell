/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:55 by vkatason          #+#    #+#             */
/*   Updated: 2023/11/09 16:38:15 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that checks if the char is space or not
 * 
 * @param c any char
 * @return true 
 * @return false 
 */
bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
