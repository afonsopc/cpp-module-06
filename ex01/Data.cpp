/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:41:18 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 19:32:58 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : value(0) {}
Data::Data(const Data &other) : value(other.value) {}
Data &Data::operator=(const Data &other) {
	this->value = other.value;
	return (*this);
}
Data::~Data(void) {}

int Data::getValue(void) const {
	return this->value;
}

void Data::setValue(int newValue) {
	this->value = newValue;
}
