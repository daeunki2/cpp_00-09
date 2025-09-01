/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:20:44 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:21:27 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{ 
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp; tmp = src->createMateria("ice");
	me->equip(tmp); tmp = src->createMateria("cure");
	me->equip(tmp); ICharacter* bob = new Character("bob");
	me->use(0, *bob); me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}