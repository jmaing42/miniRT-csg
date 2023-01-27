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

#include "t_f.h"

#include <math.h>

#if PRECISION == 0

t_f	t_f_atan2(t_f y, t_f x)
{
	return (atan2l(y, x));
}

#elif PRECISION == 1

t_f	t_f_atan2(t_f y, t_f x)
{
	return (atan2(y, x));
}

#elif PRECISION == 2

t_f	t_f_atan2(t_f y, t_f x)
{
	return (atan2f(y, x));
}

#elif PRECISION == 3

t_f	t_f_atan2(t_f y, t_f x)
{
	return ((t_f)atan2f((float)y, (float)x));
}

#endif
