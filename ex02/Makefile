# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 13:51:33 by wiozsert          #+#    #+#              #
#    Updated: 2023/04/22 20:13:24 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

OBJ = $(SRCS:.cpp=.o)

DEP = $(OBJ:%.o=%.d)

all : $(NAME)

.cpp.o:
	c++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

clean :
	rm -rf $(OBJ) $(DEP)

fclean : clean
	rm -rf $(NAME)

re : fclean all