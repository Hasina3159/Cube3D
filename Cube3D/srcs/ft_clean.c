/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/13 22:49:35 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/struct.h"
#include "../includes/functions.h"

void clean_up(t_data *data)
{
	mlx_hook(data->win, 2, 1L<<0, NULL, NULL);  // Exemple : Suppression du hook pour les événements de clavier
	mlx_hook(data->win, 17, 0L, NULL, NULL);    // Exemple : Suppression du hook pour la fermeture de la fenêtre
	mlx_loop_hook(data->mlx, NULL, NULL);
	// Libérer l'image
	if (data->img != NULL) {
		mlx_destroy_image(data->mlx, data->img);
	}

	// Libérer la fenêtre (doit être fait avant de détruire la connexion)
	if (data->win != NULL) {
		mlx_destroy_window(data->mlx, data->win);
	}

	// Libérer la connexion à la bibliothèque mlx
	if (data->mlx != NULL) {
		mlx_destroy_display(data->mlx);
		free(data->mlx);  // Ne pas oublier de libérer l'espace mémoire de mlx
	}
	exit(0);
}