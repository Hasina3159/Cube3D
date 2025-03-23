/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:19:24 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/23 11:24:27 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

t_bool	ft_check_filename(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		printf("Error\nArg number must be two!\n");
		return (0);
	}
	len = ft_strlen(argv[1]);
	if (len < 5 || !ft_strncmp((argv[1] + (len - 5)), "/.cub", 5)
		|| ft_strncmp((argv[1] + (len - 4)), ".cub", 5))
	{
		printf("Error\nInvalid filename\n");
		return (false);
	}
	return (true);
}
