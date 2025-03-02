/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:55:47 by hhammiou          #+#    #+#             */
/*   Updated: 2025/03/01 13:49:08 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

void	mini_printf(int fd, const char *format, ...);
int		ft_atoi(const char *str);
void	ft_msg_error(char *msg);

#endif