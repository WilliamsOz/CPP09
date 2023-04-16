/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:07 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/16 18:41:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*

Créer un programme qui affiche la valeur d'une certaine quantité de bitcoin à une certaine date.

Ce programme doit utiliser une base de données au format csv qui représentera le prix du bitcoin
au fil du temps. Cette base de données est fournie avec ce sujet.

Le programme prendra en entrée une deuxième base de données, stockant les différents prix/dates
évaluer.

Votre programme doit afficher sur la sortie standard le résultat de la valeur multipliée
par le taux de change selon la date indiquée dans votre base de données.

Si la date utilisée dans l'entrée n'existe pas dans votre BD alors vous
utiliser la date la plus proche contenue dans votre BD.
Veillez à utiliser la date inférieure et non supérieure.

Chaque ligne de ce fichier doit respecter le format suivant : "date | valeur".
Une date valide sera toujours au format suivant : Année-Mois-Jour.
Une valeur valide doit être soit un float, soit un int positif compris entre 0 et 1000

*/

	// for(std::map<std::string, long double>::const_iterator it = data.begin() ; it != data.end() ; ++it)
		// std::cout << it->first << " " << it->second << std::endl;

// #include <cctype>

void	exploitData(std::map<std::string, long double> data, std::string str) {
	std::map<std::string, long double>::const_iterator	it;
	std::string											date;
	long double											val;

	date = str.substr(0, str.find(" "));
	val = atoi(str.c_str() + str.find("|") + 2);
	it = data.find(date);
	if (it != data.end())
		std::cout << date << " => " << val << " = " << val * data.at(date) << std::endl;
	else {
		data[date] = val;
		it = data.find(date);
		it--;
		data.
		// P(*it)
		// std::cout << date << " => " << val << " = " << val * it << std::endl;

		P(data.at(date))
	}
	// }
	(void)data;
	EX

	return ;
}

void	checkData(std::map<std::string, long double> data, std::string str) {
	int		year;
	int		month;
	int		day;
	long	val;

	year = atoi(str.c_str());
	if (year < 2009 || year > 2022) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	month = atoi(str.c_str() + 5);
	if (month < 1 || month > 12) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	day = atoi(str.c_str() + 8);
	if (day < 1 || day > 31) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	val = atol(str.c_str() + 13);
	if (val < 0 || val > 1000) {
		if (val < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (val > 1000)
			std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	exploitData(data, str);
	return ;
}

void	readInputFile(std::map<std::string, long double> data, const char *inputFile) {
	std::fstream	ifs;
	std::string		tmp;

	ifs.open(inputFile, std::fstream::in);
	while (std::getline(ifs, tmp)) {
		if (tmp.find("date | value") == std::string::npos) {
			checkData(data, tmp);
		}
	}
	return ;
}

void	btc(const char *dataBase, const char *inputFile) {
	std::map<std::string, long double>	data;

	getData(&data, dataBase);
	readInputFile(data, inputFile);
	return ;
}

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