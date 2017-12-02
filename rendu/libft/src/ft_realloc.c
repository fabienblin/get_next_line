/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:27 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:27 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **mem, size_t size)
{
	void	*realloc;

	realloc = NULL;
	if (!(realloc = (void *)malloc(size)))
		return (NULL);
	if (*mem)
	{
		ft_memcpy(realloc, *mem, size);
		free(*mem);
		*mem = realloc;
	}
	return (realloc);
}
