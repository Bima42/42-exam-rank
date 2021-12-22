int	in_rectangle(t_shape &tmp, int x, int y)
{
	if (((x < tmp->x) || (tmp->width + tmp->x) < x)
		|| (y < tmp->y) || ((tmp->height + tmp->y) < y))
		return (0);
	if (((x - tmp->x < 1.00000000) || (tmp->width + tmp->x) - x < 1.00000000)
		|| ((y - tmp->y < 1.00000000) || ((tmp->height + tmp->y) - y < 1.00000000))
		return (2);
	return (1);
}
