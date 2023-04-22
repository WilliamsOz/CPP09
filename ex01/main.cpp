/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:23 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 20:34:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	try {
		checkArgumentErrors(ac, av[1], 0);
		rpn(av[1], 0);
	}
	catch(const std::exception& e) {
		std::cerr << REDCOLOR << e.what() << ENDCOLOR << std::endl;
	}
	return 0;
}