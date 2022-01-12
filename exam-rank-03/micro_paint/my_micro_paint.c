#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char 	color;
}				t_shape;

typedef struct s_zone
{
	int		width;
	int		height;
	char	back;
}				t_zone;

/*
** Definimos estructuras necesarias para printar: una para el fondo y otra para cada rectangulo
** Iniciamos los valores del fondo y revisamos que los argumentos sean correctos
** Abrimos el archivo, comprobando errores
** Definimos el lienzo y rellenamos un array con los caracteres que haran de fondo
** Buscamos las formas que vamos a imprimir
** Printamos todo
** Limpiamos, cerramos y liberamos
*/ 

int	check_canvas(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300);
}

int	get_canvas(t_zone *zone, FILE *file)
{
	int ret;

	if ((ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->back)) != 3)
		return (0);
	if (!check_canvas(zone))
		return (0);
	if (ret == -1)
		return (0);
	return (1);
}

char *draw_canvas(t_zone *zone)
{
	char *drawing;
	int i = 0;

	if (!(drawing = malloc(zone->height * zone->width + 1)))
		return (NULL);
	while (i < zone->width * zone->height)
	{
		drawing[i] = zone->back;
		i++;
	}
	drawing[i] = '\0';
	return (drawing);
}

int	check_shape(t_shape *shape)
{
	return(shape->width > 0 && shape->height > 0 && (shape->type == 'r' || shape->type == 'R'));
}

int	in_rect(t_shape *shape, float x, float y)
{
	if ((x < shape->x || shape->x + shape->width < x) || (y < shape->y || shape->y + shape->height < y))
		return (0);
	if (((x - shape->x < 1.00000000) || ((x + shape->width) - x < 1.00000000)) || ((y - shape->y < 1.00000000) || ((y + shape->height) - y < 1.00000000)))
		return (2);
	return (1);
}


void draw_shape(t_zone *zone, t_shape *shape, char **drawing)
{
	int i;
	int j;
	int ret;

	i = 0;
	while (i < shape->height)
	{
		j = 0;
		while (j < shape->width)
		{
			ret = in_rect(shape, j, i);
			if ((shape->type == 'r' && ret == 2) || (shape->type == 'R' && ret))
				(*drawing)[(i * zone->width) + j] = shape->color;
			j++;
		}
		i++;
	}
}

int get_shapes(t_zone *zone, FILE *file, char **drawing)
{
	t_shape tmp;
	int ret;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if (check_shape(&tmp))
			return (0);
		draw_shape(zone, &tmp, drawing);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void draw_draw(t_zone *zone, char *drawing)
{
	int i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->height), zone->height);
		write(1, "\n", 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	t_zone zone;
	char *drawing;
	FILE *file;

	drawing = NULL;
	zone.back = 0;
	zone.height = 0;
	zone.width = 0;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (!get_canvas(&zone, file))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		return (1);
	}
	if (!(drawing = draw_canvas(&zone)))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		free(drawing);
		return (1);
	}
	if (!get_shapes(&zone, file, &drawing))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		free(drawing);
		return (1);
	}
	draw_draw(&zone, drawing);
	return (0);
}