/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:50:10 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/23 19:51:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <algorithm>
# include <cmath>
# include <cstdlib>
# include <cerrno>
# include <cctype>
# include <limits>

bool	ft_str_is_double(const std::string &s);
double	ft_str_to_double(const std::string& s);

#endif
