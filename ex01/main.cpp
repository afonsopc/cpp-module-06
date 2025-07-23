/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:15:23 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 19:12:58 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
		return (1);
	}
	Data *data = new Data();
	data->setValue(std::atoi(argv[1]));
	uintptr_t serializedData = Serializer::serialize(data);
	Data *deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Original value: " << data->getValue() << std::endl;
	std::cout << "Serialized uintptr_t: 0x" << std::hex << serializedData << std::dec << std::endl;
	std::cout << "Deserialized value: " << deserializedData->getValue() << std::endl;
	delete data;
}
