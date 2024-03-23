/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:25:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/23 19:28:27 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to free a 2d array
 * 
 * @param split: a pointer to the 2d array.
 */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * @brief Function to free a 2d array
 * 
 * @param dest: a pointer to the 2d array.
 * @param i: an integer that represent the number of elements.
 */
void	free_dest(char **dest, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(dest[j++]);
	free(dest);
}

/**
 * @brief Function to duplicate a 2d array
 * 
 * @param src: a pointer to the 2d array.
 * @return char** 
 */
char	**strdup_2d(char **src)
{
	int		i;
	int		len;
	char	**dst;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dst = malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = strdup(src[i]);
		if (!dst[i])
		{
			free_dest(dst, i);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// CHECKEAR ESTAS FUNCIONES -*-*-*-*-*-*-*-*-*-*-*-*-*-*-
/*
void	free_data(t_data *data)
{
	if (data->cmd)
		free_cmd(data->cmd);
	if (data->env_copy)
		free_env(data->env_copy);
	if (data->token)
		free_token(data->token);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args)
	{
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
	}
	if (cmd->redir)
		free_redir(cmd->redir);
	free(cmd);
}

void	free_redir(t_redirect *redir)
{
	t_redirect	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		free(tmp->file);
		free(tmp->redir_type);
		free(tmp);
	}
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}
*/