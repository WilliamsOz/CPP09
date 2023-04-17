/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:21 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/17 13:38:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	allowedOp(char c) {
	if (c != '+' && c != '-' && c != '/' && c != '*')
		return false;
	else
		return true;
}

static bool	illogicSyntax(char *av, int i, int nbCount, int opCount) {
	while (av[i]) {
		if (isdigit(av[i])) {
			nbCount++;
			while (av[i] && isdigit(av[i]))
				i++;
		}
		else if (allowedOp(av[i]))
			opCount++;
		i++;
	}
	if (opCount + 1 != nbCount)
		return true;
	else
		return false;
}

static bool	syntaxError(char *av, int i, int nbCount) {
	if (illogicSyntax(av, 0, 0, 0) == true)
		return true ;
	while (av[i]) {
		if (isdigit(av[i]))
			nbCount++;
		if (nbCount == 2 && allowedOp(av[i]))
			nbCount = 1;
		else if (nbCount == 3 && allowedOp(av[i]))
			nbCount = 2;
		i++;
	}
	if (nbCount != 1)
		return true;
	else
		return false;
}

void	checkArgumentErrors(int ac, char *av, int i) {
	if (ac != 2)
		throw std::invalid_argument("Error");
	while (av[i]) {
		if ((!isdigit(av[i])) && allowedOp(av[i]) == false && av[i] != ' ')
			throw std::invalid_argument("Error");
		else
			i++;
	}
		if (syntaxError(av, 0, 0) == true)
			throw std::invalid_argument("Error");
	return ;
}