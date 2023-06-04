int	*flood_fill(char **tab, t_point size, t_point cur, char wall)
{
	static int	n[2] = {0, 0};

	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| tab[cur.y][cur.x] == wall || tab[cur.y][cur.x] == 'K')
		return (NULL);
	if (tab[cur.y][cur.x] == 'c')
		n[0]++;
	if (tab[cur.y][cur.x] == 'e')
		n[1]++;
	tab[cur.y][cur.x] = wall;
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, wall);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, wall);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, wall);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, wall);
	return ((int *)n);
}

flood_fill(m->map, (t_point){m->len_x, m->len_y}, *(data->ppos), '1');

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;