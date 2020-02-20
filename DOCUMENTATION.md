cub3d project @42born2code

# MLX

## MLX CONFIG for non-42 computer: 

[INSTALLATION TUTORIAL](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)

## COMPILATION WITH MLX:

### using X11

```shell
gcc -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext .c
```

### using terminal

```shell
gcc .c libft/.c get_next_line/*.c -L minilibx_opengl -l mlx -framework OpenGL -framework AppKit
```

#DOCUMENTATION https://github.com/keuhdall/images_example/blob/master/example.c

=====RAYCASTING==

#tutorial https://lodev.org/cgtutor/raycasting.html

#handle save flag https://engineering.purdue.edu/ece264/17au/hw/HW15
