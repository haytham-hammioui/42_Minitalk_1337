/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:43:46 by hhammiou          #+#    #+#             */
/*   Updated: 2025/03/01 13:05:27 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

void	mini_printf(int fd, const char *format, ...);
int		ft_atoi(const char *str);
void	ft_msg_error(char *msg);

#endif