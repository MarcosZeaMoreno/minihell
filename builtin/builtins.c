/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:45 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/11 17:08:27 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to handle the cd builtin
 * 
 * @param data 
 * @param usr_input 
 */
void	ft_cd(t_data *data, char *usr_input)
{
	(void)data;
	(void)usr_input;
}

/**
 * @brief Function to handle the export builtin
 * 
 * @param data 
 * @param usr_input 
 */
void	ft_export(t_data *data, char *usr_input)
{
	(void)data;
	(void)usr_input;
}

/**
 * @brief Function to handle the unset builtin
 * 
 * @param data 
 * @param usr_input 
 */
void	ft_unset(t_data *data, char *usr_input)
{
	(void)data;
	(void)usr_input;
}

/**
 * @brief Function to handle the env builtin
 * 
 * @param env
 */
void	ft_env(t_env *env)
{
	while (env->next != NULL)
	{
		ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}