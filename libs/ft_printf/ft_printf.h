/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:02:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/11/02 14:12:14 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
int		ft_printstring(char *str);
int		ft_printpercent(void);
int		ft_printnum(int n);
int		ft_printchar(char c);
int		ft_print_whole(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, const char format);
int		ft_print_ptr(unsigned long long ptr);

#endif