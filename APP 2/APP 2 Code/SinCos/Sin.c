/*
 * Sin.c
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

#define PI 3.1415
float Puissance(float nombre, int puissance);
int factoriel(int number);
float CalculSinus(float radAngle);

int main()
{
	float x = 1;
	printf("1) donnee fournie: %.2f\n resultat attendu :  0.8415\n Resultat obtenue: ", x);
	printf("%f\n\n",CalculSinus(x));
	
	float x2 = 0;
	printf("1) donnee fournie: %.2f\n resultat attendu :  0\n Resultat obtenue: ", x2);
	printf("%.2f\n\n", CalculSinus(x2));
	
	float x3 = PI/4;
	printf("1) donnee fournie: %f (PI/4)\n resultat attendu :  0.7071\n Resultat obtenue: ", x3);
	printf("%f\n\n", CalculSinus(x3));
	
	float x4 = PI/2;
	printf("1) donnee fournie: %f (PI/2)\n resultat attendu :  1\n Resultat obtenue: ", x4);
	printf("%.2f\n\n", CalculSinus(x4));
	
	
	

}
float CalculSinus(float angleRadian)
{
	
	const int nombreDeTerme = 9;
	float resultat = 0;
	//int puissance;
	int signe = 2;
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
	for (int i = 1; i < nombreDeTerme; i += 2)
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


