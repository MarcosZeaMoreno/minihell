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
 * @param token
 */
void    ft_cd(t_data *data, t_token token)
{
    char	*pwd_old;
    char	*pwd_new;

    token = token->next;
    pwd_old = get_env_value(data->env_copy, "OLDPWD");
    if (!pwd_old)
        pwd_old = get_env_value(data->env_copy, "PWD");
    if (chdir(token->value) == -1)
    {
        ft_printf("cd: %s: No such file or directory\n", token->value);
        return;
    }
    pwd_new = getcwd(NULL, 0);
    if (!pwd_new)
    {
        ft_printf("cd: error retrieving current directory\n");
        return;
    }
    change_value_env(data, "OLDPWD", pwd_old);
    change_value_env(data, "PWD", pwd_new);
    free(pwd_new);
}

/*
** Function to handle the export builtin
* @param data
* @param token
*/
void ft_export(t_data *data, t_token *token)
{
    char *key;
    char *value;
    char *delimiter_position;

	token = token->next;
    while (token != NULL)
	{
        delimiter_position = strchr(token->value, '=');
        if (delimiter_position == NULL) {
            ft_printf("export: %s: Invalid argument\n", token->value);
            return;
        }

        *delimiter_position = '\0';
        key = token->value;
        value = delimiter_position + 1;

        if (get_env_value(data->env_copy, key) != NULL)
			change_value_env(data, key, value);
        else
            add_env_var(data, key, value);
        token = token->next;
    }
}

/**
 * @brief Function to handle the unset builtin
 * 
 * @param data 
 * @param token 
 */
void    ft_unset(t_data *data, t_token token)
{
	char	*key;
	char	*delimiter_position;

	token = token->next;
	while(token != NULL)
	{
		delimiter_position = strchr(token->value, '=');
        if (delimiter_position == NULL)
		{
            ft_printf("unset: %s: Invalid argument\n", token->value);
            token = token->next;
			continue;
        }
		key = strtok(token->value, "=");
		if (get_env_value(data->env_copy, key) != NULL)
			remove_env_var(data, key);
		token = token->next;
	}
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
