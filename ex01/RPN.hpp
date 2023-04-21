/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:26 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/21 17:12:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <stack>
#include <cstdlib>
#define REDCOLOR "\033[1;31m"
#define ENDCOLOR "\033[0m"

#define P(x) std::cout << x << std::endl; //del

struct	rpnstr_s {
	char	op;
	int	(*fct)(int nb1, int nb2);
};

bool	allowedOp(char c);
void	checkArgumentErrors(int ac, char *av, int i);
void	rpn(char *av, int i);


#endif