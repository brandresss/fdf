#include "fdf.h"

int		closepg(void *param)
{
	(void)param;
	exit(0);
}

int     main(int argc, char **argv)
{
    t_fdf   *data;
    int     widthofmap;
    int     heightofmap;

    widthofmap = 1000;
    heightofmap = 800;
    if (argc == 2)
    {
        data = (t_fdf*)malloc(sizeof(t_fdf));
        read_file(argv[1], data);
        /*
        int i = 0;
        int j = 0;

        while (i < data->height)
        {
            j = 0;
            while( j < data->width)
            {
                printf("%3d ", data->z_matrix[i][j]);
                j++;
            }
            i++;
            printf("\n");
        }
        */
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, widthofmap, heightofmap, "FDF");
    data->zoom = minn(((widthofmap/2)/(data->width/2))/2, \
                 ((heightofmap/2)/(data->width/2))/2);
    //printf("z:%d\n", data->zoom);
    //printf("1:%d %d\n", data->width, data->height);
    data->shift_x = (widthofmap / 2) - ((data->width * data->zoom) / 2);
    data->shift_y = (heightofmap / 2) - ((data->height * data->zoom) / 2);
    //printf("2:%d %d\n", data->shift_x, data->shift_y);
    data->color1 = 0xFFFFFF;
    data->color2 = 0xFFFFFF;
    data->chchchaaanges = 1;
    data->isom = 0;
    data->angle = 0.8;
    data->alpha = 1;
    data->beta = 1;
    data->gamma = 1;
    draw(data);
    mlx_hook(data->win_ptr, 17, 0, closepg, data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
    }
    else
        ft_putstr("Usage: ./fdf MAP_FILE\n");
    return (0);
}
