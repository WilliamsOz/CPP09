/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:06:42 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/15 20:10:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include <map>
#include <cstring>
#include <string>
#define REDCOLOR "\033[1;31m"
#define GRNCOLOR "\033[1;32m"
#define YELCOLOR "\033[1;33m"
#define BLUECOLOR "\033[1;34m"
#define MAGCOLOR "\033[1;35m"
#define CYANCOLOR "\033[1;36m"
#define ENDCOLOR "\033[0m"

#define P(x) std::cout << x << std::endl; //del

struct date
{
	int y;
	int m;
	int d;
};

void	checkArgumentErrors(int ac, char **av);
void	getData(std::map<std::string, long double> *data, const char *dataBase);

#endif