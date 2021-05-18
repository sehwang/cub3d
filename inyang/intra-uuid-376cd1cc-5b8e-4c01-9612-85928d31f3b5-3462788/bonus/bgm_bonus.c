/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:09:50 by inyang            #+#    #+#             */
/*   Updated: 2021/05/12 20:54:27 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	music_start(void)
{
	system("afplay ./assets/bgm/aegukga.mp3 -v 0.3 &");
}

void	music_stop(void)
{
	system("killall afplay");
}
