/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:21 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/21 17:14:39 by wiozsert         ###   ########.fr       */
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

static int	add(int nb1, int nb2) {
	return (nb1 + nb2);
}

static int	minus(int nb1, int nb2) {
	return (nb1 - nb2);
}

static int	multiply(int nb1, int nb2) {
	return (nb1 * nb2);
}

static int	divide(int nb1, int nb2) {
	return (nb1 / nb2);
}

void	rpn(char *av, int i) {
	std::stack<int>	data;
	int				tmp;
	int				j = 0;
	rpnstr_s	rpns[4] = {
		{'+', &add},
		{'-', &minus},
		{'*', &multiply},
		{'/', &divide}
	};

	while (av[i]) {
		if (isdigit(av[i]))
			data.push(atoi(av + i));
		else if (allowedOp(av[i])) {
			tmp = data.top();
			data.pop();
			while (rpns[j].op != av[i])
				j++;
			tmp = rpns[j].fct(data.top(), tmp);
			j = 0;
			data.pop();
			data.push(tmp);
		}
		i++;
	}
	std::cout << data.top() << std::endl;
	return ;
}