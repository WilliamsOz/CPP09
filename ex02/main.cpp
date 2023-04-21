/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:52:02 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/21 18:11:21 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*

Votre programme doit être capable d'utiliser une suite d'entiers positifs comme argument.

Votre programme doit utiliser un algorithme de tri par fusion-insertion pour trier l'entier positif
séquence.

Si une erreur survient pendant l'exécution du programme, un message d'erreur doit s'afficher
sur la sortie standard.

Votre programme doit pouvoir gérer au moins 3000 nombres entiers différents.

Il est fortement conseillé d'implémenter votre algorithme pour chaque conteneur
et donc d'éviter d'utiliser une fonction générique.

Sur la première ligne vous devez afficher un texte explicite suivi du positif non trié
suite d'entiers.

Sur la deuxième ligne vous devez afficher un texte explicite suivi du positif trié
suite d'entiers.

Sur la troisième ligne vous devez afficher un texte explicite indiquant le temps utilisé par
votre algorithme en spécifiant le premier conteneur utilisé pour trier l'entier positif séquence.

Sur la dernière ligne vous devez afficher un texte explicite indiquant le temps utilisé par
votre algorithme en spécifiant le deuxième conteneur utilisé pour trier l'entier positif
séquence.

Le format d'affichage du temps utilisé pour effectuer votre tri est libre mais la précision choisie
doit permettre de bien voir différence entre les deux contenants utilisés.

*/

#include "PmergeMe.hpp"
#include <vector>

// for (std::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		// P(*it)

// void	sort(char **av, int i) {
// 	std::vector<int>	v;

// 	while (av[i]) {
// 		v.push_back(atoi(av[i]));
// 		i++;
// 	}
// 	i = 0;
// 	std::pair<int, int>	p[v.size()];
// 	std::vector<int>::iterator	it = v.begin();
// 	while (it != v.end()) {
// 		p[i].first = *it;
// 		it++;
// 		p[i].second = *it;
// 		if (it != v.end())
// 			it++;
// 		if (v.size() % 2 != 0 && it + 1 == v.end())
// 			break ;
// 		i++;
// 	}
// 	int count = 4;
// 	int xd = 0;
// 	while (count > 0) {
// 		P(p[xd].first)
// 		P(p[xd].second)
// 		count--;
// 		xd++;
// 	}
// 	return ;
// }

/*
1_Regroupez les éléments de X dans ⌊n/2⌋ paires d'éléments, arbitrairement,
laissant un élément non apparié s'il y a un nombre impair d'éléments.

2_Effectuer ⌊n/2⌋ comparaisons, une par paire, pour déterminer
le plus grand des deux éléments de chaque paire.

3_Trier récursivement les ⌊n/2⌋ éléments plus grands de chaque paire,
créant une séquence triée S de ⌊n/2⌋ des éléments d'entrée, par ordre croissant.

4_Insérer au début de S l'élément qui a été associé au premier et au plus petit élément de S.

5_Insérez le reste ⌈n/2⌉ −1 des éléments de X∖S dans S, un à la fois, avec un ordre d'insertion
spécialement choisi décrit ci-dessous.
Utiliser la recherche binaire dans les sous-séquences de S (comme décrit ci-dessous) pour
déterminer la position à laquelle chaque élément doit être inséré.

recherche binaire = /2 jusqu'a trouver la place.

*/

void	sort(char **av, int i) {


	return ;
}

int main(int ac, char **av) {
	try {
		checkErrors(ac, av);
		sort(av, 1);
	}
	catch(const std::invalid_argument &e) {
		std::cerr << REDCOLOR << e.what() << ENDCOLOR << '\n';
	}
	return 0;
}