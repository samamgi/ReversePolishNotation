/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:37:41 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/29 08:37:42 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : stack()
{
}

RPN::RPN(RPN const &copy) : stack(copy.stack)
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &copy)
{
	if (this == &copy)
		return (*this);
	this->stack = copy.stack;
	return (*this);
}

bool	checkline(std::string const &line)
{
	std::string::size_type i = 0;
	while (i < line.size())
	{
		if (isspace(line[i]))
		{
			i++;
			continue ;
		}
		if ((line[i] < '0' || line[i] > '9') && line[i] != '+' && line[i] != '-'
			&& line[i] != '*' && line[i] != '/')
			return (false);
		i++;
        if (i < line.size() && !isspace(line[i]))
            return (false);
	}
	return (true);
}

bool	is_operator(std::string &line, std::string::size_type i)
{
	if (i >= line.size())
		return (false);
	if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
		return (true);
	return (false);
}

bool	is_number(std::string &line, std::string::size_type i)
{
	if (i >= line.size())
		return (false);
	if (line[i] >= '0' && line[i] <= '9')
		return (true);
	return (false);
}

void RPN::pushstack(std::string &str)
{
	char	*end;
	long	tmp;
	int		value;

	errno = 0;
	tmp = std::strtol(str.c_str(), &end, 10);
	if (errno == ERANGE)
		throw(std::runtime_error("Error"));
	if (tmp < 0 || tmp > 9)
		throw(std::runtime_error("Error"));
	value = static_cast<int>(tmp);
	this->stack.push_back(value);
}

void	RPN::do_op(std::string &line, std::string::size_type index)
{
	if (index >= line.size())
		throw (std::runtime_error("Error"));
    if (this->stack.size() < 2)
        throw (std::runtime_error("Error"));
    int b = this->stack.back();
    this->stack.pop_back();
    int a = this->stack.back();
    this->stack.pop_back();
	if (line[index] == '+')
        this->stack.push_back(a + b);
	if (line[index] == '-')
        this->stack.push_back(a - b);
	if (line[index] == '*')
        this->stack.push_back(a * b);
	if (line[index] == '/')
    {
        if (b == 0)
            throw (std::runtime_error("Error"));
        this->stack.push_back(a / b);
    }
}

void RPN::setstack(std::string const &line)
{
	std::string current = line;
	std::string num;
	std::string::size_type i = 0;
	std::string::size_type start = 0;
	while (i < current.size())
	{
		while (i < current.size() && isspace(current[i]))
			i++;
		if (is_number(current, i) == true)
		{
			start = i;
			while (is_number(current, i) == true)
			{
				i++;
			}
			if (start > current.size() || (i - start) > (current.size() - start))
				throw(std::runtime_error("Error"));
			num = current.substr(start, i - start);
			this->pushstack(num);
		}
		if (is_operator(current, i) == true)
		{
			do_op(current, i);
			i++;
		}
		else
			i++;
	}
}

void    RPN::printstack()
{
    std::list<int>::iterator    i = this->stack.begin();
    while (i != this->stack.end())
    {
        std::cout << *i << std::endl;
        i++;
    }
}

void RPN::calculate(std::string const &line)
{
	if (checkline(line) == false)
		throw(std::runtime_error("Error"));
	setstack(line);
    if (this->stack.size() != 1)
        throw(std::runtime_error("Error"));
    printstack();
}
