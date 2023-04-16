/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:26 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/16 18:05:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	checkArgumentErrors(int ac, char **av)
{
	std::fstream	ifs;
	struct stat		info;

	if (ac >= 3)
		throw std::invalid_argument("Error: too many argument.");
	ifs.open(av[1], std::fstream::in);
	if (!(ifs.is_open()))
		throw std::invalid_argument("Error: could not open file.");
	else
		ifs.close();
	lstat(av[1], &info);
	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode))
		throw std::invalid_argument("Error: argument is not a file.");
	return ;
}

void	getData(std::map<std::string, long double> *data, const char *dataBase) {
	std::fstream						dataBaseFile;
	std::string							tmp;
	std::string							date;
	long double							value;

	dataBaseFile.open(dataBase, std::fstream::in);
	while (dataBaseFile) {
		dataBaseFile >> tmp;
		if (tmp.find("-") != std::string::npos) {
			date = tmp.substr(0, tmp.find(","));
			value = atof(tmp.c_str() + strlen(date.c_str()) + 1);
			(*data)[date] = value;
		}
	}
	dataBaseFile.close();
	return ;
}
