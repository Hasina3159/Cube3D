/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/03 20:17:54 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		ft_get_longest(char *content, int line_index);
char	*ft_get_data(char *content, char *data_name, int *index);

char	*get_final(char *final, char *path)
{
	if (final == NULL)
		printf("Error\n%s: Is a directory\n", path);
	return (final);
}

char	**ft_get_true_map(char *content, int line_index)
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
			free(final);
		final = tmp;
		size = read(fd, buffer, 1023);
	}
	return (get_final(final, path));
}

char	*if_get_error(int count, char *path, char *data_name, int *index)
{
	if (count > 1)
	{
		free(path);
		*index = -1;
		path = NULL;
		printf("Error\n[%s] Doublons!\n", data_name);
		return (NULL);
	}
	else if (count == 0)
	{
		printf("Error\n[%s] N'existe pas!\n", data_name);
		free(path);
		return (NULL);
	}
	return (path);
}

int	ft_check_if_all_data_exists(char *content)
{
	int		i;
	int		index;
	int		max_index;
	char	**all_data;
	char	*data;

	all_data = ft_split("NO SO WE EA F C", ' ');
	if (all_data == NULL)
		return (0);
	i = -1;
	max_index = INT_MIN;
	while (all_data[++i])
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
	}
	ft_free_split(all_data);
	return (max_index + 1);
}
