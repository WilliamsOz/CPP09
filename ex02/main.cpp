/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:52:02 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 14:11:34 by wiozsert         ###   ########.fr       */
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

void	printPair(std::pair<int, int>	tab[], int count) {
	int i = 0;

	while (i < count) {
		P(tab[i].first)
		P(tab[i].second)
		i++;
	}
	return ;
}

void	printVector(std::vector<int> v) {
	std::vector<int>::iterator	itr;

	itr = v.begin();
	while (itr != v.end()) {
		P(*itr)
		itr++;
	}
	return ;
}

void	createPair(std::pair<int, int> pairTab[], char **av, int *tmp) {
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (av[i]) {
		if (av[i + 1] == NULL) {
			*tmp = atoi(av[i]);
			break ;
		}
		pairTab[count].first = atoi(av[i]);
		i++;
		pairTab[count].second = atoi(av[i]);
		i++;
		count++;
	}
	return ;
}

void	sortPair(std::pair<int, int> pairTab[], int nbOfPair, int i) {
	int	tmp;

	while (i < nbOfPair) {
		if (pairTab[i].first > pairTab[i].second) {
			tmp = pairTab[i].first;
			pairTab[i].first = pairTab[i].second;
			pairTab[i].second = tmp;
		}
		i++;
	}
	return ;
}

bool	allNbPushed(std::pair<int, int> pairTab[], int nbOfPair, int i) {
	while (i < nbOfPair) {
		if (pairTab[i].second >= 0)
			return false;
		i++;
	}
	return true;
}

void	pushToVector(std::vector<int> *v, std::pair<int, int> pairTab[], int nbOfPair, int i) {
	int	tmp;

	tmp = pairTab[i].second;
	if (allNbPushed(pairTab, nbOfPair, 0) == true)
		return ;
	while (i < nbOfPair) {
		if (pairTab[i].second > tmp)
			tmp = pairTab[i].second;
		i++;
	}
	i = 0;
	while (i < nbOfPair) {
		if (tmp == pairTab[i].second)
			pairTab[i].second = -1;
		i++;
	}
	v->insert(v->begin(), tmp);
	pushToVector(v, pairTab, nbOfPair, 0);
	return ;
}

void	pushMinToVector(std::vector<int> *v, std::pair<int, int> pairTab[], int nbOfPair, int *keepLast) {
	int	i;
	int	tmp;

	i = 0;
	tmp = pairTab[i].first;
	while (i < nbOfPair) {
		if (pairTab[i].first < tmp)
			tmp = pairTab[i].first;
		i++;
	}
	i = 0;
	while (i < nbOfPair) {
		if (tmp == pairTab[i].first) {
			if (*keepLast > 0 && tmp < *keepLast)
				pairTab[i].first = -1;
			else {
				tmp = *keepLast;
				*keepLast = -42;
			}
			v->insert(v->begin(), tmp);
			break ;
		}
		i++;
	}
	return ;
}

void	addLastNb(std::vector<int> *v, std::pair<int, int> pairTab[], int NbOfPair, int keepLast) {
	std::vector<int>::iterator	itr;
	int							i;

	i = 0;
	while (i < NbOfPair) {
		if (pairTab[i].first > 0) {
			itr = std::lower_bound(v->begin(), v->end(), pairTab[i].first);
			v->insert(itr, pairTab[i].first);
		}
		i++;
	}
	if (keepLast > 0)
		itr = std::lower_bound(v->begin(), v->end(), keepLast);
	return ;
}

void	sort(int ac, char **av) {
	std::vector<int>		v;
	std::pair<int, int>		pairTab[ac / 2];
	int	keepLast;

	keepLast = -42;
	createPair(pairTab, av, &keepLast);
	sortPair(pairTab, ac/2, 0);
	pushToVector(&v, pairTab, ac/2, 0);
	pushMinToVector(&v, pairTab, ac/2, &keepLast);
	addLastNb(&v, pairTab, ac/2, keepLast);
	printVector(v);
	// printPair(pairTab, ac/2);
	return ;
}

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