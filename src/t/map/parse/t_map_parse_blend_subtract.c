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

#include "t_map_parse.h"

#include "ft_json.h"
#include "t_map.h"
#include "t_map_free.h"

t_err	t_map_parse_blend_subtract(t_ft_json value, t_map_blend_subtract *out)
{
	out->type = T_MAP_BLEND_TYPE_SUBTRACT;
	if (t_map_parse_color(ft_json_get_dict(value, "from"), &out->from))
		return (true);
	if (t_map_parse_color(ft_json_get_dict(value, "subtract"), &out->subtract))
	{
		t_map_free_color(out->from);
		return (true);
	}
	return (false);
}
