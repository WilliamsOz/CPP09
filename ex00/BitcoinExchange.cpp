/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:26 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/14 19:02:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	checkArgumentErrors(int ac, char **av)
{
	std::fstream	ifs;
	struct stat		info;

	if (ac >= 3) {
		std::cout << REDCOLOR "Error: too many argument." << ENDCOLOR << std::endl;
		exit (EXIT_FAILURE);
	}
	ifs.open(av[1], std::fstream::in);
	if (!(ifs.is_open())) {
		std::cout << REDCOLOR "Error: could not open file." << ENDCOLOR << std::endl;
		exit (EXIT_FAILURE);
	}
	else
		ifs.close();
	lstat(av[1], &info);
	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode)) {
		std::cout << REDCOLOR "Error: argument is not a file." << ENDCOLOR << std::endl;
		exit (EXIT_FAILURE);
	}
}
