/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:07 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/15 18:01:29 by wiozsert         ###   ########.fr       */
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

#include <cstring>
#include <string>
#include <climits>

void	btc(const char *dataBase, const char *inputFile) {
	std::map<std::string, long double>	data;
	std::fstream			dataBaseFile;
	std::string				tmp;
	std::string				date;
	long double				value;

	dataBaseFile.open(dataBase, std::fstream::in);
	while (dataBaseFile) {
		dataBaseFile >> tmp;
		if (tmp.find("-") != std::string::npos) {
			date = tmp.substr(0, tmp.find(","));
			value = atof(tmp.c_str() + strlen(date.c_str()) + 1);
			data[date] = value;
		}
		// P(date)
		// P(value)
	}
	for(std::map<std::string, long double>::const_iterator it = data.begin() ; it != data.end() ; ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
		exit (EXIT_FAILURE);
	}
	(void)inputFile;

	return ;
}

int main(int ac, char **av) {
	checkArgumentErrors(ac, av);
	btc("data.csv", av[1]);
	return 0;
}