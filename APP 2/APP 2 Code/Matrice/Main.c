/*
 * Main.c
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

//#include <limits.h>
#include <stdio.h>
// m : nombre de ligne de chaque matrice
// n : nombre de collones de chaque matrice
	
#define N 3
#define M 3

void additionMatrice(int matrice1[M][N], int matrice2[M][N], int matriceRep[M][N]);
void multiplicationMatrice(int matrice1[M][N], int matrice2[M][N], int matriceRep[M][N]);
void printMatrice(int matrice[M][N]);

int main(int argc, char **argv)
{
	
	int matrice1[M][N] = 	{{1,2,12},
							{1,6,7},
							{1,5,3}};
	
	int matrice2[M][N] = 	{{2,0,0}, 
							{0,4,0}, 
							{0,0,7}};
	
	int matriceRes[M][N] = 	{{0,0,0}, 
							{0,0,0}, 
							{0,0,0}};
							
	printMatrice(matrice1);
	printMatrice(matrice2);
	//additionMatrice(matrice1, matrice2, matriceRes);
	multiplicationMatrice(matrice1, matrice2, matriceRes);
	printMatrice(matriceRes);
	/*
	
	// multi
	int var = 0;
	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		for (int j = 0; j < 4; j++)
		{
			for (int x = 0; x < 4; x++)
			{	
				var += matrice1[i][x] * matrice2[x][j];
			}	
			matriceRes[i][j] = var;
			printf("%d ", matriceRes[i][j]);
			var = 0;
		}
	}
	*/
	
	
	//additionMatrice(matrice1,matrice2, matriceRes);

	
	return 0;
}
void printMatrice(int matrice[M][N])
{
	for (int i = 0; i < M; i++)
	{
		printf("\n");
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matrice[i][j]);
		}
	}
}
void additionMatrice(int matrice1[M][N], int matrice2[M][N], int matriceRep[M][N])
{
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matriceRep[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
}
void multiplicationMatrice(int matrice1[M][N], int matrice2[M][N], int matriceRep[M][N])
{
	int temporaire = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int x = 0; x < 3; x++)
			{
				temporaire += matrice1[i][x] * matrice2[x][j];
			}
			matriceRep[i][j] = temporaire;
			temporaire = 0;
		}
	}
}

