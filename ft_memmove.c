/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:43:31 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/13 19:09:43 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if they both are the same if so return the dst
//
// check if source - dest - n have less space ('\0' from s and d) * n
// source 10
// dst 10
// n 4
//
// 10 - 10 - 4 <= -2 * 4 ?
// -14 <= -8?
//
// than t has space (exclude 2 '\0') to safely memcpy
//
// check if dest is less than src then do loop unrolling fill 
// else just do backward copy to avoid overlap

// s1 s2 s3 s4 -> d1 d2 d3 d4 (this is fine to do forward copy)
// 0x10...0x14 -> 0x20...0x24

// s1 s2 s3 s4 -> s3 s4 d1 d2 (we need backward copy to avoid overlap)
// 0x10...0x14 -> 0x13...0x16

// if we do forward copy anyway
// s1 s2 s3 s4 -> s3 s4 d1 d2
// ->             ^^
// s1 s2 s1 s4 -> s1 s4 d1 d2
// s1 s2 s1 s4 -> s3 s4 d1 d2
//    ->             ^^
// s1 s2 s1 s2 -> s1 s2 d1 d2

// s1 s2 s1 s2 -> s1 s2 d1 d2
//       ->             ^^
// s1 s2 s1 s2 -> s1 s4 s1 d2
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (d);
	if (s - d - n <= -2 * n)
		return (ft_memcpy(d, s, n));
	if (d < s)
	{
		while (n >= 4)
		{
			*d++ = *s++;
			*d++ = *s++;
			*d++ = *s++;
			*d++ = *s++;
			n -= 4;
		}
	}
	else
		while (n--)
			d[n] = s[n];
	return (dest);
}
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
*/
