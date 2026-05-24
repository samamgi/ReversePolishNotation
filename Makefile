# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 03:37:18 by ssadi-ou          #+#    #+#              #
#    Updated: 2026/04/29 08:37:04 by ssadi-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN \

SRCS	= main.cpp \
	  RPN.cpp \

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++
CXXFLAGS	= -Wall -Wextra -Werror -fdiagnostics-color=always -std=c++98

all:	$(NAME)

$(OBJS): RPN.hpp

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
