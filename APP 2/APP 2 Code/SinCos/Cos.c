/*
 * Cos.c
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


float Puissance(float nombre, int puissance);
int factoriel(int number);
float CalculCosinus(float radAngle);

int main()
{
	printf("1) donnee fournie : 3\n resultat attendu : -0.98999 \n Resultat obtenue: ");
	float x = 2593.67;
	printf("cos de %f :%f", x, CalculCosinus(x));
}
float CalculCosinus(float angleRadian)
{
	const int nombreDeTerme = 15;
	const float PI = 3.1415;
	float resultat = 1;
	//int puissance;
	int signe = 1;
	
	// Si la valeur de l'angle radian donner n'est pas entre PI et - PI 
	// On enleve 2 PI jusqu'a avoir une valeur dedans!  
	if (angleRadian > PI){
		while (angleRadian >= PI) {
			angleRadian -= (2 * PI);
		}
	}else if (angleRadian < -PI) {
		while (angleRadian <= -PI) {
			angleRadian += (2 * PI);
		}
	}
	for (int i = 2; i < nombreDeTerme; i += 2)
	{
		resultat += (Puissance(-1, signe) * Puissance(angleRadian, i))/factoriel(i);
		signe++;
	}
	return resultat;
}

float Puissance(float nombre, int puissance)
{
	float resultat = 1;
	if (puissance == 0)
		return 1;
	else if (puissance < 0)
	{
		for (int i = 0; i < -puissance; i++) {
			
            resultat *= nombre;
        }
        return (1 / resultat);
	}
	resultat = nombre;
	for (int i = 1; i < puissance; i++)
	{
		resultat *= nombre;
	}
	return resultat;
}
int factoriel(int number)
{
	if (number == 0)
		return 1;
	else if (number < 0)
		return -1;

	int facto = 1;
	for (int i = 1; i <= number; i++)
	{
		facto *= i;
	}
	return facto;
}
