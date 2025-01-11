
#include "vector.h"
#include "header.h"

t_vector	*ft_vect_add(t_vector *v1, t_vector *v2)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = v1->x + v2->x;
	res->y = v1->y + v2->y;
	res->z = v1->z + v2->z;
	return (res);
}

t_vector	*ft_vect_mult_vv(t_vector *v1, t_vector *v2)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = v1->x * v2->x;
	res->y = v1->y * v2->y;
	res->z = v1->z * v2->z;
	return (res);
}

t_vector	*ft_vect_mult_cv(double a, t_vector *v)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = v->x * a;
	res->y = v->y * a;
	res->z = v->z * a;
	return (res);
}

t_vector	*ft_vect_div_vv(t_vector *v1, t_vector *v2)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = v1->x / v2->x;
	res->y = v1->y / v2->y;
	res->z = v1->z / v2->z;
	return (res);
}

t_vector	*ft_vect_div_vc(double a, t_vector *v)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = a / v->x;
	res->y = a / v->y;
	res->z = a / v->z;
	return (res);
}

t_vector	*ft_vect_div_cv(t_vector *v, double a)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = v->x / a;
	res->y = v->y / a;
	res->z = v->z / a;
	return (res);
}

double	ft_vect_len(t_vector *v)
{
	return (sqrt(sqr(v->x) + sqr(v->y) + sqr(v->z)));
}

double	ft_vect_dot_product(t_vector *v1, t_vector *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

t_vector	*ft_vect_cross_product(t_vector *v1, t_vector *v2)
{
	t_vector	*res;

	res = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (res == NULL)
		return (NULL);
	res->x = ((v1->y * v2->z) - (v1->z * v2->y));
	res->x = ((v1->z * v2->x) - (v1->x * v2->z));
	res->x = ((v1->x * v2->y) - (v1->y * v2->x));
	return (res);
}