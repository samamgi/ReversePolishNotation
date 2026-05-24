/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:37:38 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/29 08:45:47 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <cerrno>
# include <climits>
# include <cstdlib>
# include <iostream>
# include <list>
# include <string>
# include <cctype>

class RPN
{
  private:
	std::list<int> stack;

  public:
	RPN();
	RPN(const RPN &copy);
	~RPN();

	RPN &operator=(RPN const &copy);

	void calculate(std::string const &line);

	void pushstack(std::string &str);

	void setstack(std::string const &line);

	void do_op(std::string &line, std::string::size_type index);

	void printstack();
};

#endif
