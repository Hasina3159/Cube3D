/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:08:50 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/01 11:57:38 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*if_get_error(int count, char *path, char *data_name, int *index);

void	ft_print_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		printf("%d : %s\n", i, map[i]);
		i++;
	}
	return ;
}

char	**ft_get_map(char *content, int line_index)
{
	int		i;
	int		count;
	char	**map;

	i = 0;
	count = 0;
	line_index++;
	while (i < ft_strlen(content) && count < line_index)
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	if (count == line_index)
		map = ft_split((content + i), '\n');
	else
		map = NULL;
	return (map);
}

int	ft_get_longest(char *content, int line_index)
{
	int		longest;
	int		i;
	char	**map;

	map = ft_get_map(content, line_index);
	if (map == NULL)
		return (0);
	longest = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > longest)
			longest = ft_strlen(map[i]);
		i++;
	}
	ft_free_split(map);
	return (longest);
}

int	pp(char *to_split, int *count, char *data_name, char **path)
{
	char	**split_path;

	split_path = ft_split(to_split, ' ');
	if (split_path[0] == NULL)
		return (1);
	if (ft_strncmp(data_name, split_path[0], ft_strlen(data_name)) == 0
		&& ft_get_split_size(split_path) == 2)
	{
		(*count)++;
		if (*count == 1)
			*path = ft_strdup(split_path[1]);
		ft_free_split(split_path);
		return (2);
	}
	ft_free_split(split_path);
	return (0);
}

char	*ft_get_data(char *content, char *data_name, int *index)
{
	int		i;
	int		count;
	char	**splitted;
	char	*path;
	int		pp_res;

	splitted = ft_split(content, '\n');
	path = NULL;
	if (splitted == NULL)
		return (NULL);
	i = -1;
	count = 0;
	while (splitted[++i])
	{
		pp_res = pp(splitted[i], &count, data_name, &path);
		if (pp_res == 1)
			continue ;
		else if (pp_res == 2)
		{
			if (count == 1)
				*index = i;
		}
	}
	ft_free_split(splitted);
	return (if_get_error(count, path, data_name, index));
}
