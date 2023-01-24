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

#include "t_map_polynomial_plane.h"

#include <stdbool.h>

int	t_map_polynomial_plane_validate_repeat_minus(char c)
{
	if ('1' <= c && c <= '9')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_COEFFICIENT_DIGIT_FIRST);
	if (c == 'x')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_X);
	if (c == 'y')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Y);
	if (c == 'z')
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_REPEAT_Z);
	else
		return (
			T_MAP_POLYNOMIAL_PLANE_PARSE_STATE_ERROR);
}
