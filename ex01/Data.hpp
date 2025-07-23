/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:41:18 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 19:32:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
	private:
		int	value;
	public:
		Data(void);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data(void);
		int		getValue(void) const;
		void	setValue(int newValue);
};

#endif
