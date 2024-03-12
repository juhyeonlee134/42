/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:01:39 by juhyelee          #+#    #+#             */
/*   Updated: 2023/09/08 21:06:49 by juhyelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parsing.h"
// #include "game.h"

// int	main(int argc, char *argv[])
// {
// 	t_game	*game;

// 	if (argc == 2)
// 	{
// 		game = NULL;
// 		if (init(argv[1], &game))
// 			loop(game);
// 	}
// 	else if (argc > 2)
// 		print_error(ARGS_LIST_TOO_LONG);
// 	else
// 		print_error(INVALIED_FILE);
// 	return (0);
// }

#include "../mlx/mlx.h"
#include <math.h>
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 280

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	main(int argc, char *argv[])
{
	//player
	// player position
	float	pos_x = 22;
	float	pos_y = 12;
	// player direction
	float	dir_x = -1;
	float	dir_y = 0;
	// player camera
	float	plane_x = 0;
	float	plane_y = 0.66;
	// player fov
	float fov = 2 * atan(plane_y/2);
	// frame time -> check FPS and event
	float	time = 0;		// currnet time
	float	old_time = 0;	// prev time
	void	*mlx;
	void	*win;

	//init window
	mlx = mlx_init();
	win = mlx_new_window(mlx, screenWidth, screenHeight, "cub3d");

	while (1)
	{
		//shoot raycast
		// shoot virtical
		for (int x = 0; x < (int)fov; x++)
		{
			float	cam_x = 2 * x / fov - 1;
			float	ray_dir_x = dir_x + plane_x * cam_x;
			float	ray_dir_y = dir_x + plane_x * cam_x;

			// dda algorithm
			int	map_x = (int)pos_x;
			int	map_y = (int)pos_y;
			// distance from player x to first x side
			float	side_dist_x;
			// distance from plyaer y to first y side
			float	side_dist_y;
			// distance from first x side to next x side
			float	delta_dist_x = (float)fabs(1 / ray_dir_x);
			// distance from first y side to next y side
			float	delta_dist_y = (float)fabs(1 / ray_dir_y);
			// total distance
			float	perp_wall_dist;

			int	step_x;
			int	step_y;

			int	is_hit = 0;
			int	is_side;


		}
	}
	return (0);
}