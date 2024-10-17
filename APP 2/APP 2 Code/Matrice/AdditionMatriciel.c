#include <stdio.h>

#define M 3
#define N 2

void printMatrice(float matrice[M][N]);
void additionMatrice(float matrice1[M][N], float matrice2[M][N], float matriceRep[M][N]);

int main()
{
	/*
	// test
	float matrice1[M][N] = 	{{1,2,12,3},
							{1,6,7,5},
							{1,5,3,7}};
	
	float matrice2[M][N] = 	{{2,0,0,4},
							{0,4,0,6}, 
							{0,0,7,9}};
	
	float matriceRep[M][N];
	*/
	float matrice1[M][N] = {{1,2},
							{3,4},
							{5,6}};
	float matrice2[M][N] = {{6,5},
							{4,3},
							{2,1}};
	float matriceResultatAttendu[M][N] = {{7,7},
										  {7,7},
										  {7,7}};		
	float matriceRep[M][N];
	
						
	printf("Donner fournies\nmatrice 1 : \n");
	printMatrice(matrice1);
	printf("\n\nmatrice 2: \n");
	printMatrice(matrice2);
	
	printf("\n\nresultat attendu:\n");
	printMatrice(matriceResultatAttendu);
	
	
	additionMatrice(matrice1, matrice2, matriceRep);
	printf("\n\nla reponse de l'addition est :");
	printMatrice(matriceRep);

	return 0;
}




void additionMatrice(float matrice1[M][N], float matrice2[M][N],
float matriceRep[M][N])
{
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matriceRep[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
}
void printMatrice(float matrice[M][N])
{
	for (int i = 0; i < M; i++)
	{
		printf("\n");
		for (int j = 0; j < N; j++)
		{
			printf("%.2f ", matrice[i][j]);
		}
	}
}
