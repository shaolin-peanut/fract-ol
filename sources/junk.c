while (x < WW)
        {
                while (y < WH)
                {
                        c.r = 1.5 * (x - WW / 2) / (0.5 * vars->zoom * WW) + vars->moveX;
                        c.i = (y - WH / 2) / (0.5 * vars->zoom * WH) + vars->moveY;
                        z.r = 0;
                        z.i = 0;
                        i = 0;

                        while (i < ITERATION_MAX)
                        {
                                tmp.i = z.i;
                                tmp.r = z.r;
                                z.r = pow(tmp.r, 2) - pow(tmp.i, 2) + c.r;
                                z.i = 2 * tmp.i * tmp.r + c.i;
                                if (pow(z.r, 2) + pow(z.i, 2) > 4.0)
                                        break;
                                i++;
                        }
                        if (i == ITERATION_MAX)
                                my_mlx_pixel_put(&img, x, y, 0x00000000);
                        else
                                my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
                        y++;
                }
                y = 0;
                x++;
        }
