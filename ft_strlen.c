/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:14 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:39 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* experimenting bsd implementation
static inline size_t	ft_sptr(const char *p, const char *s, int x)
{
	if (p[x] == '\0')
		return (p - s + x);
	return (size_t)(-1);
}

size_t	ft_strlen(const char *s)
{
	const char		*p;
	const unsigned long	*lp;
	long			va;
	long			vb;
	size_t			res;

	lp = (const unsigned long *)((unsigned long)s & ~(sizeof(long) - 1));
	va = (*lp - 0x01010101);
	vb = ((~*lp) & 0x80808080);
	lp++;
	if (va & vb)
	{
		while (p < (const char *)lp)
		{
			if (*p == '\0')
				return (p - s);
			p++;
		}
	}
	while (lp)
	{
		va = (*lp - 0x01010101);
		vb = ((~*lp) & 0x80808080);
		if (va & vb)
		{
			p = (const char *)(lp);
			if ((res = ft_sptr(p, s, 0)) != (size_t)(-1)) return res;	
			if ((res = ft_sptr(p, s, 1)) != (size_t)(-1)) return res;	
			if ((res = ft_sptr(p, s, 2)) != (size_t)(-1)) return res;	
			if ((res = ft_sptr(p, s, 3)) != (size_t)(-1)) return res;	
		}
	}
	return (res);
}
*/
// musl implementation

size_t	ft_strlen(const char *s)
{
	const char	*a;

	a = s;
	while (*s)
		s++;
	return (s - a);
}

// musl #2 need more research not safe to use
/*
size_t	align_to_word(const char **s, const char *a)
{
	while ((unsigned long)*s % sizeof(unsigned long))
	{
		if (!**s)
			return (*s - a);
		(*s)++;
	}
	return (0);
}

int	has_zero_byte(unsigned long x)
{
	unsigned long	ones;
	unsigned long	highs;

	ones = (unsigned long)-1 / 255;
	highs = ones * (255/2 + 1);
	return (((x - ones) & ~x & highs) != 0);
}

size_t	find_zero_byte(const unsigned long *w, const char *a)
{
	const char	*s;

	s = (const char *)w
	while (*s)
		s++;
	return (s - a);
}

size_t	ft_strlen(const char *s)
{
	const char		*a;
	size_t			len;
	const unsigned long	*w 

	a = s;
	len = align_to_word(&s, a);
	if (len)
		return len;
	w = (const unsigned long *)s;
	while (!has_zero_byte(*w))
		w++;
	return (find_zero_byte(w, a));
}
*/
