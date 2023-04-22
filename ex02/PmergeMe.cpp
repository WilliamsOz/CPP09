/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:29:41 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/22 20:27:10 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	isPositiveNumSeq(char **av, int i, int j) {
	while (av[i]) {
		while (av[i][j]) {
			if (av[i][j] < '0' || av[i][j] > '9')
				throw std::invalid_argument("Error");
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

static void	isInteger(char **av, int i) {
	unsigned long long	tmp;

	while (av[i]) {
		tmp = atoi(av[i]);
		if (tmp > 2147483647)
			throw std::invalid_argument("Error");
		i++;
	}
	return ;
}

void	checkErrors(int ac, char **av) {
	if (ac < 3)
		throw std::invalid_argument("Error");
	isPositiveNumSeq(av, 1, 0);
	isInteger(av, 0);
	return ;
}

static void	createPair(std::pair<int, int> pairTab[], char **av, int *tmp) {
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

static void	sortPair(std::pair<int, int> pairTab[], int nbOfPair, int i) {
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

static bool	allNbPushed(std::pair<int, int> pairTab[], int nbOfPair, int i) {
	while (i < nbOfPair) {
		if (pairTab[i].second >= 0)
			return false;
		i++;
	}
	return true;
}

static void	pushToVector(std::vector<int> **v, std::pair<int, int> pairTab[], int nbOfPair, int i) {
	int	tmp;

	if (allNbPushed(pairTab, nbOfPair, 0) == true)
		return ;
	tmp = pairTab[i].second;
	i++;
	while (i < nbOfPair) {
		if (pairTab[i].second > tmp)
			tmp = pairTab[i].second;
		i++;
	}
	i = 0;
	while (i < nbOfPair) {
		if (tmp == pairTab[i].second) {
			pairTab[i].second = -1;
			break ;
		}
		i++;
	}
	(*v)->insert((*v)->begin(), tmp);
	pushToVector(v, pairTab, nbOfPair, 0);
	return ;
}

static void	pushMinToVector(std::vector<int> **v, std::pair<int, int> pairTab[], int nbOfPair, int *keepLast) {
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
			if (*keepLast >= 0 && tmp >= *keepLast) {
				tmp = *keepLast;
				*keepLast = -42;
			}
			else
				pairTab[i].first = -1;
			(*v)->insert((*v)->begin(), tmp);
			break ;
		}
		i++;
	}
	return ;
}

static void	addLastNbToVector(std::vector<int> **v, std::pair<int, int> pairTab[], int NbOfPair, int keepLast) {
	std::vector<int>::iterator	itr;
	int							i;

	i = 0;
	while (i < NbOfPair) {
		if (pairTab[i].first > 0) {
			itr = std::lower_bound((*v)->begin(), (*v)->end(), pairTab[i].first);
			(*v)->insert(itr, pairTab[i].first);
		}
		i++;
	}
	if (keepLast > 0) {
		itr = std::lower_bound((*v)->begin(), (*v)->end(), keepLast);
		(*v)->insert(itr, keepLast);
	}
	return ;
}

static void	vectorSort(std::vector<int> *v, int ac, char **av) {
	std::pair<int, int>		pairTab[ac / 2];
	int	keepLast;

	keepLast = -42;
	createPair(pairTab, av, &keepLast);
	sortPair(pairTab, ac/2, 0);
	pushToVector(&v, pairTab, ac/2, 0);
	pushMinToVector(&v, pairTab, ac/2, &keepLast);
	addLastNbToVector(&v, pairTab, ac/2, keepLast);
	return ;
}

static void	pushToDeque(std::deque<int> **d, std::pair<int, int> pairTab[], int nbOfPair, int i) {
	int	tmp;

	if (allNbPushed(pairTab, nbOfPair, 0) == true)
		return ;
	tmp = pairTab[i].second;
	i++;
	while (i < nbOfPair) {
		if (pairTab[i].second > tmp)
			tmp = pairTab[i].second;
		i++;
	}
	i = 0;
	while (i < nbOfPair) {
		if (tmp == pairTab[i].second) {
			pairTab[i].second = -1;
			break ;
		}
		i++;
	}
	pushToDeque(d, pairTab, nbOfPair, 0);
	(*d)->insert((*d)->begin(), 1, tmp);
	return ;
}

static void	pushMinToDeque(std::deque<int> **d, std::pair<int, int> pairTab[], int nbOfPair, int *keepLast) {
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
			if (*keepLast >= 0 && tmp >= *keepLast) {
				tmp = *keepLast;
				*keepLast = -42;
			}
			else
				pairTab[i].first = -1;
			(*d)->insert((*d)->begin(), tmp);
			break ;
		}
		i++;
	}
	return ;
}

static void	addLastNbToDeque(std::deque<int> **d, std::pair<int, int> pairTab[], int NbOfPair, int keepLast) {
	std::deque<int>::iterator	itr;
	int							i;

	i = 0;
	while (i < NbOfPair) {
		if (pairTab[i].first > 0) {
			itr = std::lower_bound((*d)->begin(), (*d)->end(), pairTab[i].first);
			(*d)->insert(itr, pairTab[i].first);
		}
		i++;
	}
	if (keepLast > 0) {
		itr = std::lower_bound((*d)->begin(), (*d)->end(), keepLast);
		(*d)->insert(itr, keepLast);
	}
	return ;
}

static void	dequeSort(std::deque<int> *d, int ac, char **av) {
	std::pair<int, int>		pairTab[ac / 2];
	int	keepLast;

	keepLast = -42;
	createPair(pairTab, av, &keepLast);
	sortPair(pairTab, ac/2, 0);
	pushToDeque(&d, pairTab, ac/2, 0);
	pushMinToDeque(&d, pairTab, ac/2, &keepLast);
	addLastNbToDeque(&d, pairTab, ac/2, keepLast);
	return ;
}

static void	displayInfo(char **av, std::vector<int>	v, std::deque<int>d, timer t) {
	std::vector<int>::iterator	itr;
	int							i;

	i = 1;
	std::cout << "Before: ";
	while (av[i]) {
		std::cout << atoi(av[i]) << " ";
		i++;
	}
	std::cout << std::endl;
	itr = v.begin();
	std::cout << "After: ";
	while (itr != v.end()) {
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " <<
	v.size() << " elements with std::vector : " <<
	((((long double)t.vectortimer)/CLOCKS_PER_SEC) * 1000)
	<< " ms" << std::endl;
	std::cout << "Time to process a range of " <<
	d.size() << " elements with std::deque : " <<
	((((long double)t.dequetimer)/CLOCKS_PER_SEC) * 1000)
	<< " ms" << std::endl;
	return ;
}

void	sort(int ac, char **av) {
	std::vector<int>		v;
	std::deque<int>			d;
	timer					timeInfo;

	timeInfo.start = std::clock();
	vectorSort(&v, ac, av);
	timeInfo.vectortimer = std::clock() - timeInfo.start;
	timeInfo.start = std::clock();
	dequeSort(&d, ac, av);
	timeInfo.dequetimer = std::clock() - timeInfo.start;
	displayInfo(av, v, d, timeInfo);
	return ;
}