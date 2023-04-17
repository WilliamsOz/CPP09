/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:26 by wiozsert          #+#    #+#             */
/*   Updated: 2023/04/17 13:38:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <stack>
#define REDCOLOR "\033[1;31m"
#define ENDCOLOR "\033[0m"

#define P(x) std::cout << x << std::endl; //del

bool	allowedOp(char c);
void	checkArgumentErrors(int ac, char *av, int i);


#endif