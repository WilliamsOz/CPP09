/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:10:24 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 15:20:21 by wiozsert         ###   ########.fr       */
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
#define REDCOLOR "\033[1;31m"
#define ENDCOLOR "\033[0m"

#define P(x) std::cout << x << std::endl; //del

struct timer
{
	clock_t	start;
	clock_t	vectortimer;
	clock_t	dequetimer;
};

void	checkErrors(int ac, char **av);
void	displayInfo(char **av, std::vector<int> v, timer t);

#endif