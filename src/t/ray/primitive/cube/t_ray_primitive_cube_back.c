/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ray_primitive_cube.h"

#include "ft_types.h"
#include "t_map.h"
#include "t_ray.h"

typedef struct s_locals
{
	t_f				distance;
	t_map_position	point;
	t_f				x;
	t_f				y;
	bool			is_front_face;
}	t_locals;

static bool is_in_square(t_map_cube cube, t_map_position point)
{
	if (point.y < cube.position.y || point.y > cube.position.y + cube.size.y)
		return (false);
	if (point.z < cube.position.z || point.z > cube.position.z + cube.size.z)
		return (false);
	return (true);
}

t_err	t_ray_primitive_cube_back(
			t_ray ray,
			t_map_cube cube,
			t_ray_hit_records_builder *builder)
{
	t_locals	l;

	// plane's normal : (-1,0,0)
	l.distance = - (ray.origin.x * -1 - cube.position.x) / (ray.direction.x * -1);
	l.point = t_f3_add(ray.origin, t_f3_mul(ray.direction, l.distance));

	l.x = l.point.x / cube.size.x;
	l.y = l.point.y / cube.size.y;
	if (l.distance < 0 || !is_in_square(cube, l.point))
		return (false);
	l.is_front_face = ray.direction.z > 0;
	return (t_ray_hit_records_builder_add(builder, (t_ray_hit_record){
		l.distance,
		(t_map_normal){-1, 0, 0},
		t_ray_material_from_color(cube.material_back),
		l.is_front_face,
		l.x,
		l.y
		})
	);
}
