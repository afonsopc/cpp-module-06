/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:49:42 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 20:22:04 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

static bool	is_digit_of_double(char c) {
	return (isdigit(c) || c == '.' || c == '+');
}

bool	ft_str_is_double(const std::string &s) {
	std::string::const_iterator begin = s.begin() + (s[0] == '-');
	bool has_f_suffix = !s.empty() && s[s.length() - 1] == 'f';
	std::string::const_iterator end = s.end() - (has_f_suffix ? 1 : 0);

	if (begin == end || *begin == '.' || std::count(begin, end, '.') > 1)
		return (false);
	for (std::string::const_iterator it = begin; it != end; ++it)
		if (!is_digit_of_double(*it))
			return (false);
	return (true);
}

double	ft_str_to_double(const std::string& s) {
	double	value;

	if (s == "inf" || s == "+inf" || s == "+inff")
		return (std::numeric_limits<double>::infinity());
	if (s == "-inf" || s == "-inff")
		return (-std::numeric_limits<double>::infinity());
	if (s == "nan" || s == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	if (!ft_str_is_double(s))
		return (std::numeric_limits<double>::quiet_NaN());
	value = strtod(s.c_str(), NULL);
	if (errno == ERANGE)
		return (std::numeric_limits<double>::quiet_NaN());
	return (value);
}
