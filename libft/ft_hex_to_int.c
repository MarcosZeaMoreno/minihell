/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:33:55 by vkatason          #+#    #+#             */
/*   Updated: 2023/09/24 14:19:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hex_to_int(char *hex)
{
	int		result;
	int		val;

	result = 0;
	while (*hex)
	{
		if ('0' <= *hex && *hex <= '9')
			val = *hex - '0';
		else if ('a' <= *hex && *hex <= 'f')
			val = *hex - 'a' + 10;
		else if ('A' <= *hex && *hex <= 'F')
			val = *hex - 'A' + 10;
		else
			return (-1);
		result = (result << 4) + val;
		hex++;
	}
	return (result);
}
