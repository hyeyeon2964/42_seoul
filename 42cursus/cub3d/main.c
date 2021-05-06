#include <stdlib.h>
#include "cub3d.h"

int	exit_error(t_game *game, char const *str)
{
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
		exit_game(game, EXIT_FAILURE);
		return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game game;
	int save_opt;

	save_opt = (argc >= 2 && !ft_strcmp(argv[1], "-save"));
	if (argc < (2 + save_opt))
		return (sxit_error(&game, "Error:\n savq option error \n"));
	init_game(&game, save_opt);
	if (!parse_config(&game.config, argv[1 + save_opt]))
		return (EXIT_FAILURE);
	if (game.option & FLAG_SAVE)
		return (screenshot(&game));
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.window.ptr, &main_loop, &game);
	mlx_loop(game.window.ptr);
	return (EXIT_SUCCESS);
}
