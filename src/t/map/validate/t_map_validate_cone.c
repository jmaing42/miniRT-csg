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

#include "t_map_validate.h"

#include <stdbool.h>

#include "ft_json.h"

bool	has_optional_material(t_ft_json value)
{
	t_ft_json	material;

	if (!ft_json_dict_has_key(value, "material"))
		return (true);
	material = ft_json_get_dict(value, "material");
	if (t_map_validate_material(material))
		return (true);
	return (
		true
		&& ft_json_is_list(material)
		&& ft_json_list_length(material) == 2
		&& t_map_validate_material(ft_json_get_list(material, 0))
		&& t_map_validate_material(ft_json_get_list(material, 1))
	);
}

bool	t_map_validate_cone(t_ft_json value)
{
	return (
		true
		&& t_map_validate_has_type(value, "cone")
		&& t_map_validate_has_position(value)
		&& t_map_validate_has_size(value)
		&& t_map_validate_has_rotation(value)
		&& has_optional_material(value)
	);
}
