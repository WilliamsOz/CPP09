/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:23 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/21 17:11:24 by wiozsert         ###   ########.fr       */
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