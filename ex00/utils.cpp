/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:49:42 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 15:50:09 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

static bool	is_digit_of_double(char c) {
	return (isdigit(c) || c == '.' || c == '+');
}

bool	ft_str_is_double(const std::string &s) {
	std::string::const_iterator begin = s.begin() + (s[0] == '-');
	std::string::const_iterator end = s.end() - (s.back() == 'f');

	if (begin == end || begin[0] == '.' || std::count(begin, end, '.') > 1)
		return (false);
	return (std::all_of(begin, end, ::is_digit_of_double));
}

double	ft_str_to_double(const std::string& s) {
	double	value;

	if (s == "+inf" || s == "+inff")
		return (INFINITY);
	if (s == "-inf" || s == "-inff")
		return (-INFINITY);
	if (!ft_str_is_double(s))
		return (nan(""));
	value = strtod(s.c_str(), NULL);
	if (errno == ERANGE || value < -2147483648 || value > 2147483647)
		return (nan(""));
	return (value);
}
