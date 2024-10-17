/*
 * Recherche d’un caractère.c
 * 
 * Copyright 2024 yohan <yohan@MSI>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

int RechercheChar(char chaineDeCaracteres[], char characteresRecherche);

int main(int argc, char **argv)
{
	char chaineDeCaracteres [] = "anticonstitutionnellement";
	char characteresRecherche = 'n'; 
	printf("1) donnee fournie : %s et lettre : %c\n resultat attendu: 1 (index)\n Resultat obtenue: ", chaineDeCaracteres, characteresRecherche);
	printf("%d\n\n", RechercheChar(chaineDeCaracteres, characteresRecherche));
	
	char chaineDeCaracteres2 [] = "bonjour";
	char characteresRecherche2 = 'e'; 
	printf("2) donnee fournie : %s et lettre : %c\n resultat attendu: -1 (index)\n Resultat obtenue: ", chaineDeCaracteres2, characteresRecherche2);
	printf("%d\n\n", RechercheChar(chaineDeCaracteres2, characteresRecherche2));
	
	char chaineDeCaracteres3 [] = "bonjour";
	char characteresRecherche3 = 'r'; 
	printf("3) donnee fournie : %s et lettre : %c\n resultat attendu: 6 (index)\n Resultat obtenue: ", chaineDeCaracteres3, characteresRecherche3);
	printf("%d\n\n", RechercheChar(chaineDeCaracteres3, characteresRecherche3));
	
	char chaineDeCaracteres4 [] = "allocommentcava";
	char characteresRecherche4 = 'a'; 
	printf("4) donnee fournie : %s et lettre : %c\n resultat attendu: 0 (index)\n Resultat obtenue: ", chaineDeCaracteres4, characteresRecherche4);
	printf("%d\n\n", RechercheChar(chaineDeCaracteres4, characteresRecherche4));
	
	return 0;
}

int RechercheChar(char chaineDeCharacter[], char characteresRecherche)
{	
	int i = 0;
	while (chaineDeCharacter[i] != '\0')
	{
		if(chaineDeCharacter[i] == characteresRecherche)
			return i;
		i++;
	}
	return -1;
}

