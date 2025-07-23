/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:48:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 18:12:02 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

template<typename T>
static std::string	parse(const std::string &value_str) {
	std::ostringstream	stream;
	double				value;

	value = ft_str_to_double(value_str);
	if ((isnan(value) && ((value_str != "nan" && value_str != "nanf") || !std::is_floating_point<T>::value))
		|| (std::is_same<T, char>::value && !isascii(value))) {
		value = static_cast<int>(value_str[0]);
		if (value_str.length() != 1)
			return ("impossible");
	} else if (!std::is_floating_point<T>::value && (value == INFINITY || value == -INFINITY))
		return ("impossible");
    if (std::is_floating_point<T>::value)
        stream << std::fixed << std::setprecision(1);
	if (std::is_same<T, char>::value) {
		if (isprint(static_cast<T>(value)))
			stream << "'" << static_cast<T>(value) << "'";
		else
			stream << "Non displayable";
	}
	else
		stream << static_cast<T>(value);
	if (std::is_same<T, float>::value)
		stream << "f";
	return (stream.str());
}

void	ScalarConverter::convert(const std::string value) {
	std::cout << "char: " << parse<char>(value) << std::endl;
	std::cout << "int: " << parse<int>(value) << std::endl;
	std::cout << "float: " << parse<float>(value) << std::endl;
	std::cout << "double: " << parse<double>(value) << std::endl;
}
