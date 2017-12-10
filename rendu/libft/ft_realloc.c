/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:27 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/10 16:48:54 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **mem, size_t size)
{
	void	*real;

	real = NULL;
	if (!(real = (void *)malloc(size)))
		return (NULL);
	if (*mem)
	{
		ft_memcpy(real, *mem, size);
		free(*mem);
	}
	*mem = real;
	return (real);
}
