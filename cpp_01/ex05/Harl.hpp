/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:35:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/11 20:53:41 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream> // cout, cin
#include <string> // string

class Harl
{
	private:
	
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	public:
	Harl();
	~Harl();
	void    complain( std::string level );


};

#endif
