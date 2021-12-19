#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
	int	width;
	int	height;
	char	background;
}			t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}			t_shape;

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	str_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300
		&& zone->height > 0 && zone->height <= 300);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int	scan_ret;

	if ((scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	if (scan_ret == -1)
		return (0);
	return (1);
}

int	clear(FILE *file, char *drawing)
{
	fclose(file);
	if (drawing)
		free(drawing);
	return (1);
}

char	*paint_background(t_zone *zone)
{
	char	*map;
	int	i;

	if (!(map = (char *)malloc(sizeof(char) * (zone->width * zone->height))))
		return (NULL);
	i = 0;
	while (i < zone->width * zone->height)
		map[i++] = zone->background;
	return (map);

}

int	check_shape(t_shape *tmp)
{
	return (tmp->width > 0.00000000 && tmp->height > 0.00000000
		&& (tmp->type == 'r' || tmp->type == 'R'));
}

int	in_rectangle(float x, float y, t_shape *shape)
{
	if (x < shape->x || x > shape->x + shape->width
		|| y < shape->y || y > shape->y + shape->height)
		return (0);
	if ((x - shape->x < 1.00000000) || ((shape->x + shape->width) - x < 1.00000000)
		|| (y - shape->y < 1.00000000) || ((shape->y + shape->height) - y < 1.00000000))
		return (2);
	return (1);
}

void	draw_shape(char **drawing, t_shape *tmp, t_zone *zone)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			ret = in_rectangle(x, y, tmp);
			if ((tmp->type == 'r' && ret == 2)
				|| (tmp->type == 'R' && ret))
				(*drawing)[(y * zone->width + x)] = tmp->color;
			x++;
		}
		y++;
	}
}

int	draw_shapes(FILE *file, char **drawing, t_zone *zone)
{
	int		scan_ret;
	t_shape	tmp;

	while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if (!check_shape(&tmp))
			return (0);
		draw_shape(drawing, &tmp, zone);
	}
	if (scan_ret != -1)
		return (0);
	return (1);
}

void	draw_term(char *drawing, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_zone	zone;
	char	*drawing;
	FILE	*file;

	zone.height = 0;
	zone.width = 0;
	zone.background = 0;
	if (argc != 2)
		return (str_error("Error: argument\n",1));
	if (!(file = fopen(argv[1], "r")))
		return (str_error("Error: Operation file corrupted\n", 1));
	if (!get_zone(file, &zone))
		return (clear(file, NULL) && str_error("Error: Operation file corrupted\n", 1));
	if (!(drawing = paint_background(&zone)))
		return (clear(file, NULL) && str_error("Error: Malloc failed\n", 1));
	if (!draw_shapes(file, &drawing, &zone))
		return (clear(file, NULL) && str_error("Error: Operation file corrupted\n", 1));
	draw_term(drawing, &zone);
	clear(file, drawing);
	return (0);
}
