/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:27 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 18:58:18 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_strlen(s) >= i)
	{
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
