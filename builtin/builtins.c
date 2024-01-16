/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:45 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/12 17:35:19 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to handle the cd builtin
 * 
 * @param data 
 * @param usr_input 
 */
void    ft_cd(t_data *data, char *usr_input)
{
	char	*pwd_old;

	pwd_old = get_env_value(data->env_copy, "OLDPWD");
	if (!pwd_old)
		pwd_old = get_env_value(data->env_copy, "PWD");
	if (chdir(usr_input) == -1)
	{
		ft_printf("cd: %s: No such file or directory\n", usr_input);
		return ;
	}
	change_value_env(data, "OLDPWD", pwd_old);
	change_value_env(data, "PWD", usr_input);
}

/*
** Function to handle the export builtin
* @param data
* @param usr_input
*/
void ft_export(t_data *data, char *usr_input)
{
    char *key;
    char *value;
    char *delimiter_position;

    delimiter_position = strchr(usr_input, '=');
    if (delimiter_position == NULL) {
        ft_printf("export: %s: Invalid argument\n", usr_input);
        return;
    }

    *delimiter_position = '\0';
    key = usr_input;
    value = delimiter_position + 1;

    if (get_env_value(data->env_copy, key) != NULL) {
        change_value_env(data, key, value);
    } else {
        add_env_var(data, key, value);
    }
}

/**
 * @brief Function to handle the unset builtin
 * 
 * @param data 
 * @param usr_input 
 */
void    ft_unset(t_data *data, char *usr_input)
{
	char *key;

	key = usr_input;
	if (get_env_value(data->env_copy, key) != NULL)
		remove_env_var(data, key);
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
