/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:45 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/09 18:23:45 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to handle the echo builtin
 * 
 * @param data 
 * @param usr_input 
 */
void    ft_echo(t_data *data, char *usr_input)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    if (usr_input[4] == '-')
    {
        if (usr_input[5] == 'n')
            flag = 1;
    }
    while (usr_input[i] != '\0')
    {
        ft_printf("%c", usr_input[i]);
        i++;
    }
    if (flag == 0)
        ft_printf('\n', 1);
}

/**
 * @brief Function to handle the cd builtin
 * 
 * @param data 
 * @param usr_input 
 */
void    ft_cd(t_data *data, char *usr_input)
{
}

/**
 * @brief Function to handle the pwd builtin
 * 
 * @param data 
 */
void    ft_pwd(t_data *data)
{
    ft_printf("%s\n", data->cwd);
}

/**
 * @brief Function to handle the export builtin
 * 
 * @param data 
 * @param usr_input 
 */
void    ft_export(t_data *data, char *usr_input)
{
}

/**
 * @brief Function to handle the unset builtin
 * 
 * @param data 
 * @param usr_input 
 */
void    ft_unset(t_data *data, char *usr_input)
{
}

/**
 * @brief Function to handle the env builtin
 * 
 * @param env
 */
void    ft_env(t_env *env)
{
    while (env->next != NULL)
    {
        ft_printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
}
