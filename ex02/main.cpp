/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:16:00 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 19:37:03 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <unistd.h>

int	main(void) {
	Base*	ptr;

	std::cout << "=== Testing random generation and identification ===" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "\nTest " << i + 1 << ":" << std::endl;
		ptr = generate();
		std::cout << "Identify by pointer: ";
		identify(ptr);
		std::cout << "Identify by reference: ";
		identify(*ptr);
		delete ptr;
		usleep(100000);
	}
	std::cout << "\n=== Testing specific instances ===" << std::endl;
	A a;
	B b;
	C c;
	std::cout << "\nTesting A instance:" << std::endl;
	std::cout << "By pointer: ";
	identify(&a);
	std::cout << "By reference: ";
	identify(a);
	std::cout << "\nTesting B instance:" << std::endl;
	std::cout << "By pointer: ";
	identify(&b);
	std::cout << "By reference: ";
	identify(b);
	std::cout << "\nTesting C instance:" << std::endl;
	std::cout << "By pointer: ";
	identify(&c);
	std::cout << "By reference: ";
	identify(c);
}
