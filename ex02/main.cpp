/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:52:02 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 20:26:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	try {
		checkErrors(ac, av);
		sort(ac - 1, av);
	}
	catch(const std::invalid_argument &e) {
		std::cerr << REDCOLOR << e.what() << ENDCOLOR << '\n';
	}
	return 0;
}