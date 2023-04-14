/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:07 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/14 19:06:45 by wiozsert         ###   ########.fr       */
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

*/

int main(int ac, char **av) {
	checkArgumentErrors(ac, av);

	return 0;
}