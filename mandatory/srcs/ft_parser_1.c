/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:26:32 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/23 11:23:28 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

char	*read_file(int fd)
{
	char	*final;
	char	*tmp;
	char	buffer[1024];
	int		size;

	final = NULL;
	size = read(fd, buffer, 1023);
	while (size > 0)
	{
		buffer[size] = 0;
		if (final == NULL)
			tmp = ft_strjoin("", buffer);
		else
			tmp = ft_strjoin(final, buffer);
		free(final);
		final = tmp;
		size = read(fd, buffer, 1023);
	}
	return (final);
}

char	*ft_get_content(char *path)
{
	int		fd;
	char	*content;

	if (!ft_check_file_validity(path))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	content = read_file(fd);
	if (!content)
		printf("Error\n%s: Is a directory\n", path);
	return (content);
}

t_bool	ft_check_data(int count, char *path, int *index, char *data_name)
{
	if (count > 1)
	{
		free(path);
		*index = -1;
		path = NULL;
		printf("Error\n[%s] Doublons!\n", data_name);
		return (false);
	}
	if (count == 0)
	{
		printf("Error\n-> [%s] N'existe pas!\n", data_name);
		free(path);
		return (false);
	}
	return (true);
}

char	*ft_extract_path(char **split_path, int *count, int i, int *index)
{
	char	*path;

	path = NULL;
	if (ft_get_split_size(split_path) == 2)
	{
		(*count)++;
		if (*count == 1)
		{
			*index = i;
			path = ft_strdup(split_path[1]);
		}
	}
	return (path);
}
/*
void	ft_parse_lines(char **splitted, char *data_name, 
char **path, int *count, int *index)
{
	int		i;
	char	**split_path;

	i = 0;
	while (splitted[i])
	{
		split_path = ft_split(splitted[i], ' ');
		if (split_path[0] != NULL && ft_strncmp(data_name, 
		split_path[0], ft_strlen(data_name)) == 0)
			*path = ft_extract_path(split_path, count, i, index);
		ft_free_split(split_path);
		i++;
	}
}
*/

char	*ft_get_data(char *content, char *data_name, int *index)
{
	char	**splitted;
	char	*path;
	int		count;
	int		i;
	char	**split_path;

	splitted = ft_split(content, '\n');
	if (splitted[0] == NULL)
		return (NULL);
	path = NULL;
	count = 0;
	i = 0;
	while (splitted[i])
	{
		split_path = ft_split(splitted[i], ' ');
		if (split_path[0] != NULL && ft_strncmp(data_name, split_path[0],
				ft_strlen(data_name)) == 0)
			path = ft_extract_path(split_path, &count, i, index);
		ft_free_split(split_path);
		i++;
	}
	ft_free_split(splitted);
	if (ft_check_data(count, path, index, data_name) == false)
		return (NULL);
	return (path);
}
