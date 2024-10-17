/*
 * SinCos.c
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
typedef struct {
    float result;    // Résultat de l'angle
    int error;       // 0 si succès, 1 si erreur
} AngleResult;

// Calcul du sinus avec une série
AngleResult CalculSinus(float radAngle);
// Calcul du cosinus avec une série
AngleResult CalculCosinus(float radAngle);
// Calcul la factoriel d'un nombre
int factoriel(int number);
// Calcul la puissance
float power(float number, int power);

int main(int argc, char **argv)
{
	//AngleResult res = CalculCosinus(2);
	
	AngleResult res = CalculSinus(3.14);
	if (res.error == 1)
		printf("error, number out of range");
	else
		printf("Rad angle is :%f", res.result);
	
	return 0;
}

float power(float number, int power)
{
	float resultat = 1;
	if (power == 0)
		return 1;
	else if (power < 0)
	{
		for (int i = power; i <= 0; i++)
		{
			resultat *= 1 / number;
		}
		return resultat;
	}
	for (int i = 0; i < power - 1; i++)
	{
		resultat *= number;
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
AngleResult CalculSinus(float radAngle)
{
	const int numberOfTerm = 8;
	const float PI = 3.1415;
	int sign = 2;
	
	AngleResult res;
	if (radAngle > PI || radAngle < - PI)
	{
		res.error = 1; 
		return res;
	}
	res.result = 0;
	res.error = 0;
	
	for (int i = 1; i < numberOfTerm; i += 2)
	{
		res.result += (power(-1, sign) * power(radAngle, i))/factoriel(i);
		sign++;
	} 
	return res;
}

AngleResult CalculCosinus(float radAngle)
{
	const int numberOfTerm = 10;
	const float PI = 3.1415;
	int sign = 1;
	AngleResult res;
	
	if (radAngle > PI || radAngle < - PI)
	{
		res.error = 1; 
		return res;
	}
	res.result = 1.0;
	res.error = 0;
	for (int i = 2; i < numberOfTerm; i += 2)
	{
		res.result += (power(-1, sign) * power(radAngle, i))/factoriel(i);
		sign++;
	}
	return res;
}


