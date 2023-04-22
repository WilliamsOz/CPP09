/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:10:24 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 20:22:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <deque>
#define REDCOLOR "\033[1;31m"
#define ENDCOLOR "\033[0m"

#define P(x) std::cout << x << std::endl; //del
void	printPair(std::pair<int, int>	tab[], int count);
void	printVector(std::vector<int> v);
void	printDeque(std::deque<int> d);

struct timer
{
	clock_t	start;
	clock_t	vectortimer;
	clock_t	dequetimer;
};

void	checkErrors(int ac, char **av);
void	sort(int ac, char **av);

#endif