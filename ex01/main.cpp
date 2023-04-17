/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:23 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/17 13:50:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*

Le nom du programme est RPN.

Votre programme doit prendre une expression mathématique polonaise inversée comme argument.

Les nombres utilisés dans cette opération et passés en arguments seront toujours inférieurs à 10.
Le calcul lui-même mais aussi le résultat ne tiennent pas compte de cette règle.

Votre programme doit traiter cette expression et afficher le résultat correct sur la sortie standard.

Si une erreur survient pendant l'exécution du programme,
un message d'erreur doit être affiché sur la sortie standard.

Votre programme doit pouvoir gérer les opérations avec ces operateur : "+ - / *".

Vous n'avez pas besoin de gérer les parenthèses ou les nombres décimaux.

*/

// int	add(int nb1, int nb2) {
// 	return (nb1 + nb2);
// }

// int	minus(int nb1, int nb2) {
// 	return (nb1 - nb2);
// }

// int	mult(int nb1, int nb2) {
// 	return (nb1 * nb2);
// }

// int	div(int nb1, int nb2) {
// 	return (nb1 / nb2);
// }

// struct main
// {
	
	// char op;
// };


void	rpn(char *av, int i) {
	std::stack<int>	data;
	int				tmp;

	while (av[i]) {
		if (isdigit(av[i]))
			data.push(atoi(av + i));
		else if (allowedOp(av[i])) {
			tmp = data.top();
			data.pop();
			if (av[i] == '+')
				tmp = data.top() + tmp;
			else if (av[i] == '-')
				tmp = data.top() - tmp;
			else if (av[i] == '*')
				tmp = data.top() * tmp;
			else if (av[i] == '/')
				tmp = data.top() / tmp;
			data.pop();
			data.push(tmp);
		}
		i++;
	}
	std::cout << data.top() << std::endl;
	return ;
}

int	main(int ac, char **av) {
	try {
		checkArgumentErrors(ac, av[1], 0);
		rpn(av[1], 0);
	}
	catch(const std::exception& e) {
		std::cerr << REDCOLOR << e.what() << ENDCOLOR << std::endl;
	}
	return 0;
}