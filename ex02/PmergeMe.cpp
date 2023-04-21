/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:29:41 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/21 14:30:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	isPositiveNumSeq(char **av, int i, int j) {
	while (av[i]) {
		while (av[i][j]) {
			if (av[i][j] < '0' || av[i][j] > '9')
				throw std::invalid_argument("Error");
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

static void	isInteger(char **av, int i) {
	unsigned long long	tmp;

	while (av[i]) {
		tmp = atoi(av[i]);
		if (tmp > 2147483647)
			throw std::invalid_argument("Error");
		i++;
	}
	return ;
}

void	checkErrors(int ac, char **av) {
	if (ac < 3)
		throw std::invalid_argument("Error");
	isPositiveNumSeq(av, 1, 0);
	isInteger(av, 0);
	return ;
}