/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:48:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 20:44:43 by afpachec         ###   ########.fr       */
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
	bool				is_float_type;

	is_float_type = (typeid(T) == typeid(float) || typeid(T) == typeid(double));
	value = ft_str_to_double(value_str);
	if (isnan(value)) {
		if (value_str == "nan" || value_str == "nanf") {
			if (!is_float_type) 
				return ("impossible");
		}
		else {
			if (value_str.length() != 1)
				return ("impossible");
			value = static_cast<double>(value_str[0]);
		}
	}
	if (!is_float_type && (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity()))
		return ("impossible");
	if (typeid(T) == typeid(int) || typeid(T) == typeid(char)) {
		if (value > std::numeric_limits<T>::max() || value < std::numeric_limits<T>::min())
			return ("impossible");
	}
	if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
		stream << std::fixed << std::setprecision(1);
	if (typeid(T) == typeid(char) && std::numeric_limits<T>::is_integer) {
		if (isprint(static_cast<int>(value)))
			stream << "'" << static_cast<char>(value) << "'";
		else
			stream << "Non displayable";
	}
	else
		stream << static_cast<T>(value);
	if (typeid(T) == typeid(float) && std::numeric_limits<T>::has_infinity)
		stream << "f";
	return (stream.str());
}

void	ScalarConverter::convert(const std::string value) {
	std::cout << "char: " << parse<char>(value) << std::endl;
	std::cout << "int: " << parse<int>(value) << std::endl;
	std::cout << "float: " << parse<float>(value) << std::endl;
	std::cout << "double: " << parse<double>(value) << std::endl;
}
