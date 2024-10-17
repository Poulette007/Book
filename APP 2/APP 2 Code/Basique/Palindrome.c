/*
 * Palindrome.c
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
int EstPalindrome(char chaineDeCaracteres[]);

int main(int argc, char **argv)
{
	printf("1) donnee fournie : canac\n resultat attendu : retourne 1 et affiche (valeur retournee) C'est un Palindrome\n Resultat obtenue: ");
	
	char chaineDeCaracteres[] = "canac";
	
	int palindrome = EstPalindrome(chaineDeCaracteres);
	if (palindrome == 1)
		printf("(%d) C'est un Palindrome", palindrome);
	else
		printf("(%d) Ce n'est pas un Palindrome", palindrome);
	
	
	printf("\n2) donnee fournie : hello world\n resultat attendu : retourne 0 et affiche (valeur retournee) Ce n'est pas un Palindrome\n Resultat obtenue: ");
	char chaineDeCaracteres2[] = "hello world";
	
	palindrome = EstPalindrome(chaineDeCaracteres2);
	if (palindrome == 1)
		printf("(%d) C'est un Palindrome", palindrome);
	else
		printf("(%d)Ce n'est pas un Palindrome", palindrome);
	
	
	
	return 0;
}
int EstPalindrome(char chaineDeCaracteres[])
{
	int taille = 0;
	while (chaineDeCaracteres[taille] != '\0')
		taille++;
	
	char palindrome [taille + 1];
	int j = taille -1;
	for (int i = 0; i < taille; i++)
	{
		palindrome[j] = chaineDeCaracteres[i];
		j--;
	}
	palindrome[taille] = '\0';
	for (int i = 0; i < taille; i++)
	{
		if(palindrome[i] != chaineDeCaracteres[i])
			return 0;
	}
	return 1;
}



