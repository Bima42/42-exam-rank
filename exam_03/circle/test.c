int	in_circle(float x, float y, t_shape *tmp)
{
	float distance;

	distance = sqrtf(powf(x - tmp->x, 2.) + powf(y - tmp->y, 2.));
	if (distance <= tmp->radius)
	{
		if (tmp->radius - distance < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}
