/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabehar <nrabehar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:23:21 by nrabehar          #+#    #+#             */
/*   Updated: 2024/04/04 10:27:00 by nrabehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	throw(char *msg)
{
	fflush(stdout);
	fprintf(stderr, "Error : %s\n", msg);
	exit(EXIT_FAILURE);
}

static void	ft_error_handler(i32 signal_num)
{
	if (signal_num == SIGSEGV)
		tester_putstr(BOLD RED "SIGSEGV" RESET);
	else if (signal_num == SIGKILL)
		tester_putstr(BOLD RED "TIMEOUT" RESET);
	else if (signal_num == SIGILL)
		tester_putstr(BOLD RED "FORBIDDEN" RESET);
	else
		tester_putstr(BOLD RED "CRASH" RESET);
}

void	ft_handle_error(void)
{
	signal(SIGSEGV, ft_error_handler);
	signal(SIGKILL, ft_error_handler);
	signal(SIGILL, ft_error_handler);
}
