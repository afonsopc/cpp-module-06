/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:48:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 19:53:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { return ((void)other, *this); }
ScalarConverter::~ScalarConverter(void) {}

template<typename T>
static std::string	parse(const std::string &value_str) {
	std::ostringstream	stream;
	double				value;

	value = ft_str_to_double(value_str);
	if (value != value && value_str != "nan" && value_str != "nanf") {
		if (value_str.length() != 1)
			return ("impossible");
		value = static_cast<double>(value_str[0]);
	}
	bool is_float_type = (sizeof(T) == sizeof(float) && std::numeric_limits<T>::has_infinity) ||
						 (sizeof(T) == sizeof(double) && std::numeric_limits<T>::has_infinity);
	if (!is_float_type && (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity()))
		return ("impossible");
	if (sizeof(T) == sizeof(float) || sizeof(T) == sizeof(double))
		stream << std::fixed << std::setprecision(1);
	if (sizeof(T) == sizeof(char) && std::numeric_limits<T>::is_integer) {
		if (value >= 0 && value <= 127 && isprint(static_cast<int>(value)))
			stream << "'" << static_cast<char>(value) << "'";
		else
			stream << "Non displayable";
	}
	else
		stream << static_cast<T>(value);
	if (sizeof(T) == sizeof(float) && std::numeric_limits<T>::has_infinity)
		stream << "f";
	return (stream.str());
}

void	ScalarConverter::convert(const std::string value) {
	std::cout << "char: " << parse<char>(value) << std::endl;
	std::cout << "int: " << parse<int>(value) << std::endl;
	std::cout << "float: " << parse<float>(value) << std::endl;
	std::cout << "double: " << parse<double>(value) << std::endl;
}
