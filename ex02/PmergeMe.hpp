/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:10:24 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/21 14:29:58 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>
#define REDCOLOR "\033[1;31m"
#define ENDCOLOR "\033[0m"

#define P(x) std::cout << x << std::endl; //del

void	checkErrors(int ac, char **av);

#endif