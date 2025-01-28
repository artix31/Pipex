/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:33:02 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/17 17:52:29 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

int		ft_putchar(char c);
int		ft_putitox(unsigned int nb, char size);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
int		ft_putuns(unsigned int nb);
int		ft_putvoid(void *v);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *func, ...);

#endif
