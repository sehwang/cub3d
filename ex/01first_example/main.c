#include "../mlx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

int		main(void)
{
	t_mlx *mlx;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);
}
