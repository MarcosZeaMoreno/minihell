/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:31:30 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/26 20:12:42 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_name(char *name)
{
	int	i;

	i = 0;
	if (!ft_isalpha(name[i]) && name[i] != '_')
		return (1);
	i++;
	while (name[i] != '\0')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

char	*trim_spaces(const char *str)
{
	const char	*end = str + ft_strlen(str) - 1;

	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (ft_strdup_const(str));
	while (end > str && ft_isspace((unsigned char)*end))
		end--;
	return (ft_strndup(str, end - str + 1));
}

void	handle_export_null_equal_sign(t_export_args *args)
{
	if (args->equal_sign == NULL)
	{
		ft_printf_fd(1, "export: %s: Invalid argument\n", args->cmd_copy);
		free(args->cmd_copy);
		return ;
	}
	else if (*(args->equal_sign - 1) != ' ')
	{
		*args->equal_sign = '\0';
		args->key = trim_spaces(args->cmds[args->i]);
		args->value = trim_spaces(args->equal_sign + 1);
	}
	else
	{
		free(args->cmd_copy);
		args->i++;
		return ;
	}
}

void	handle_export(t_data *data, t_export_args *args)
{
	handle_export_null_equal_sign(args);
	if (args->key == NULL || check_name(args->key))
	{
		ft_printf_fd(1, "export: %s: Invalid argument\n", args->cmd_copy);
		free(args->key);
		free(args->value);
		free(args->cmd_copy);
		return ;
	}
	if (get_env_value(data->env_copy, args->key) != NULL)
		change_value_env(data, args->key, args->value);
	else
		add_env_var(data, args->key, args->value);
	free(args->key);
	free(args->value);
	free(args->cmd_copy);
}

void	ft_export(t_data *data, char **cmds)
{
	int				i;
	t_export_args	args;

	i = 1;
	if (cmds[1] == NULL)
		ft_env(data->env_copy, 1);
	else
	{
		while (cmds[i] != NULL)
		{
			args.cmd_copy = ft_strdup_const(cmds[i]);
			args.equal_sign = ft_strchr(cmds[i], '=');
			args.cmds = cmds;
			args.i = i;
			handle_export(data, &args);
			i++;
		}
	}
}
