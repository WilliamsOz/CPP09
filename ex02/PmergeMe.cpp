/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:29:41 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 16:10:41 by wiozsert         ###   ########.fr       */
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

void	displayInfo(char **av, std::vector<int>	v, timer t) {
	std::vector<int>::iterator	itr;
	int							i;

	i = 1;
	std::cout << "Before: ";
	while (av[i]) {
		std::cout << atoi(av[i]) << " ";
		i++;
	}
	std::cout << std::endl;
	itr = v.begin();
	std::cout << "After: ";
	while (itr != v.end()) {
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " <<
	v.size() << " elements with std::vector : " <<
	((((long double)t.vectortimer)/CLOCKS_PER_SEC) * 1000)
	<< " ms" << std::endl;
	return ;
}
