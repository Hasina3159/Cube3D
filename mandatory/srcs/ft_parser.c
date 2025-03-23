/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/23 09:15:41 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

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
	i = 0;
	index = 0;
	max_index = INT_MIN;
	while (all_data[i])
	{
		data = ft_get_data(content, all_data[i++], &index);
		if (index > max_index)
			max_index = index;
		if (data == NULL && ft_free_split(all_data))
			return (0);
		free(data);
	}
	ft_free_split(all_data);
	return (max_index + 1);
}

char	**ft_get_map(char *content, int line_index)
{
	int		i;
	int		count;
	char	**map;

	i = 0;
	count = 0;
	line_index++;
	while (i < (int)ft_strlen(content) && count < line_index)
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
		if ((int)ft_strlen(map[i]) > longest)
			longest = (int)ft_strlen(map[i]);
		i++;
	}
	ft_free_split(map);
	return (longest);
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
	while (i < (int)ft_strlen(content) && count < line_index)
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
		return ;
	i = 0;
	while (map[i])
	{
		printf("%d : %s\n", i, map[i]);
		i++;
	}
	return ;
}
