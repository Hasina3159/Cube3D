/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/20 16:16:15 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../includes/defines.h"
#include "../includes/functions.h"

char	*ft_get_content(char *path)
{
	int		fd;
	int		size;
	char	*final;
	char	*tmp;
	char	buffer[1024];

	if (ft_check_file_validity(path) == false)
		return (NULL);
	final = NULL;
	tmp = NULL;
	fd = open(path, O_RDONLY);
	size = read(fd, buffer, 1023);
	while (size > 0)
	{
		buffer[size] = 0;
		if (final)
			tmp = ft_strjoin(final, buffer);
		else
			tmp = ft_strjoin("", buffer);
		if (final != NULL)
			free (final);
		final = tmp;
		size = read(fd, buffer, 1023);
	}
	if (final == NULL)
		printf("Error\n%s: Is a directory\n", path);
	return (final);
}

char	*ft_get_data(char *content, char *data_name, int *index)
{
	int		i;
	int		count;
	char	**splitted;
	char	**split_path;
	char	*path;

	splitted = ft_split(content, '\n');
	path = NULL;
	if (splitted[0] == NULL)
		return (NULL);
	i = 0;
	count = 0;
	while (splitted[i])
	{
		split_path = ft_split(splitted[i], ' ');
		if (split_path[0] == NULL)
			continue;
		if (ft_strncmp(data_name, split_path[0], ft_strlen(data_name)) == 0 && ft_get_split_size(split_path) == 2)
		{
			count++;
			if (count == 1)
			{
				*index = i;
				path = ft_strdup(split_path[1]);
			}
		}
		ft_free_split(split_path);
		i++;
	}
	if (count > 1)
	{
		free (path);
		*index = -1;
		path = NULL;
		printf("Error!\n[%s] Doublons!\n", data_name);
	}
	else if (count == 0)
		printf("Error!\n[%s] N'existe pas!\n", data_name);
	ft_free_split(splitted);
	return (path);
}

int	ft_check_if_all_data_exists (char *content)
{
	int		i;
	int		index;
	int		max_index;
	char	**all_data;
	char	*data;

	all_data = ft_split("NO SO WE EA F C", ' ');
	if (all_data == NULL)
		return (0);
	i = 0;
	max_index = INT_MIN;
	while (all_data[i])
	{
		data = ft_get_data(content, all_data[i], &index);
		if (index > max_index)
			max_index = index;
		if (data == NULL)
		{
			ft_free_split(all_data);
			return (-1);
		}
		free(data);
		i++;
	}
	ft_free_split(all_data);
	return (max_index + 1);
}


char **ft_get_map(char *content, int line_index)
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

char **ft_get_true_map(char *content, int line_index)
{
	int		i;
	int		count;
	char	**map;
	int		size;

	i = 0;
	count = 0;
	line_index++;
	size = ft_get_longest(content, line_index);
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

void	ft_print_map(char **map)
{
	int	i;

	if (map == NULL)
		return;
	i = 0;
	while (map[i])
	{
		printf("%d : %s\n", i, map[i]);
		i++;
	}
	return;
}