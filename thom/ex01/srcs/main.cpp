/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:25:04 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 22:32:38 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// What the hell is that ?
    // Initialisez une pile vide.
    // Lisez l'expression de gauche à droite.
    // Si l'élément actuel est un opérande (un nombre), empilez-le sur la pile.
    // Si l'élément actuel est un opérateur, dépilez les deux éléments supérieurs de la pile.
    // Appliquez l'opérateur aux éléments dépliés, le premier opérande étant l'élément supérieur de la pile et le deuxième opérande étant l'élément suivant de la pile.
    // Empilez le résultat obtenu.
    // Répétez les étapes 3 à 6 jusqu'à ce que tous les éléments de l'expression aient été traités.
    // Le résultat final est le seul élément restant sur la pile.

// Exemples :
	// 		"3 4 +" 				(équivalent à 3 + 4)
    // 		"5 2 * 8 +" 			(équivalent à 5 * 2 + 8)
    // 		"2 7 +" 				(équivalent à 2 + 7)
    // 		"9 2 - 4 +" 			(équivalent à 9 - 2 + 4)
    // 		"6 3 * 4 2 * +" 		(équivalent à 6 * 3 + 4 * 2)
    // 		"4 2 / 6 +" 			(équivalent à 4 / 2 + 6)
    // 		"5 2 1 + 4 * + 3 -" 	(équivalent à 5 + (2 + 1) * 4 - 3)
    // 		"8 2 3 ^ ^" 			(équivalent à 8^(2^3))
    // 		"10 2 / 3 2 ^ +" 		(équivalent à 10 / 2 + 3^2)
    // 		"7 2 * 4 5 * 6 - +" 	(équivalent à 7 * 2 + 4 * 5 - 6)


int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cout << "Usage : ./rnp \"calc to do\"" << std::endl;
		return 1;
	}
	rpn.calc(argv[1]);
	return 0;
}
