/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:07 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 20:35:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	try {
		checkArgumentErrors(ac, av);
		btc("data.csv", av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << REDCOLOR << e.what() << ENDCOLOR << std::endl;
	}
	return 0;
}