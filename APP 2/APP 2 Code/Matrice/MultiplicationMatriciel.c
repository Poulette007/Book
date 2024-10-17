#include <stdio.h>

#define N 3

void PrintMatrice(float matrice[N][N]);
void MultiplicationMatrice(float matrice1[N][N], float matrice2[N][N], float matriceRep[N][N]);

int main()
{
		
	float matrice1[N][N] = 	{{-5,9,-12},
							{0.5,-4,0},
							{0.7,0.89,-8}};
	
	float matrice2[N][N] = 	{{5,3,-6}, 
							{1,-4,0.5}, 
							{1,-0.4,0.5}};
	
	float matriceRes[N][N];
							
	MultiplicationMatrice(matrice1, matrice2, matriceRes);
	PrintMatrice(matriceRes);
}

void MultiplicationMatrice(float matrice1[N][N], float matrice2[N][N], 
float matriceRep[N][N])
{
	float temporaire = 0;
	for (int i = 0; i < N; i++)
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

void PrintMatrice(float matrice[N][N])
{
	for (int i = 0; i < N; i++)
	{
		printf("\n");
		for (int j = 0; j < N; j++)
		{
			printf("%f ", matrice[i][j]);
		}
	}
}
