// Fichier: formatif.c
// Auteur: VOTRE NOM (VOTRE CIP)
// Date: 2024/10/02
// Description: Examen formatif GEN146

#include <stdio.h>

//Options utilisees dans le menu
#define CONVERSION_F_EN_C   1
#define INVERSER            2
#define PLONGEURS           3
#define EST_TRIANGULAIRE    4
#define SORTIR              5

/********************************************************************
 * Vous devez programmer vos fonctions dans cette section du programme
 * *******************************************************************/

void conversion_f_en_c(int fahrenheit)
{
	int fa = fahrenheit - 5;
	float Temperature[10][2];
	for (int i = 0; i < 10; i++)
	{
		Temperature[i][0] = fa;
		Temperature[i][1] = (5.0/9.0)*(fa - 32);
		fa++;
	}
	printf("FahrenheitCelsius");
	for (int i = 0; i < 10; i++)
	{
		printf("\n%.0f        %.2f", Temperature[i][0], Temperature[i][1]);
	}
}

void inverser_chaine(char chaine[], char chaine_inversee[])
{
	int taille = 0;
	int inverse = 0; // variable inverser de taille
	while (chaine[taille] != '\0')
	{
		taille++;
	}
	printf("\n");
	for (int i = taille; i >= 0; i--)
	{
		chaine_inversee[inverse] = chaine[i];
		printf("%c", chaine_inversee[inverse]);
		inverse++;
	}
	printf("\n");
}

int vainqueur(int juge1[12], int juge2[12], int juge3[12])
{
	// nombre max et index
	int max[2] = {0,0};
	float point;
	for (int i = 0; i < 12; i++)
	{
		point = (juge1[i] + juge2[i] + juge3[i]) / 3.0;
		printf("%.2f\n", point);
		if(point > max[0]) {
			max[0] = point;
			max[1] = i;
		}
	}
	return max[1];
}

int est_triangulaire_superieure(int matrice[4][4])
{
	// regarde pour tout les cases directement puisque nous savons que c'est du 4 par 4
	// justification : pour un code des if en serie dans un return ne demande pas beaucoup contrairement a une boucle ce code est donc plus rapide et concis 
	return (matrice[1][0] == 0 && matrice[2][0] == 0 &&  matrice[3][0] == 0 && matrice[2][1] == 0 && matrice[3][1] == 0 && matrice[3][2] == 0); 
}

/***********************************************************************************
 * Fonction main(), ne rien changer à partir de cette ligne
 * ********************************************************************************/
int main ()
{
    int choix = 0;

    //Variables de test pour l'inversion de chaines
	char chaine1[100] = "Bonjour le monde!";
	char chaine_retournee[100] = "";
	char chaine2[100] = "Voici un texte qu'on va inverser!";

    //Variables pour la fonction de plongeurs
    int juge1[12] = { 6, 8, 5, 8, 1, 9, 10, 8, 7, 6, 5, 9 };
    int juge2[12] = { 8, 8, 6, 7, 3, 8, 10, 9, 8, 7, 6, 8 };
    int juge3[12] = { 8, 8, 6, 7, 2, 10, 8, 7, 7, 7, 6, 7 };
    int le_vainqueur=0;

    //Variables pour le test de matrice superieure
    int matrice1[4][4] = { { 7, 9, 2, 8 }, { 0, 7, 4, 6 }, 
                           { 0, 0, 6, 4 }, { 0, 0, 0, 2 } };
    int matrice2[4][4] = { { 8, 4, 3, 4 }, { 0, 7, 1, 1 }, 
                           { 0, 0, 6, 1 }, { 4, 0, 0, 2 } };
    int resultat;

	// Afficher le menu tant que l'option 9 (Sortir) n'a pas ete selectionne
	while (choix != SORTIR)
	{
	    printf ("\n");
		printf ("------------------------------------------------------\n");
		printf ("Examen formatif GEN146\n");
		printf ("------------------------------------------------------\n");
		printf ("\n");
		printf ("1. Conversion F en C\n");
		printf ("2. Inverser\n");
		printf ("3. Plongeurs\n");
		printf ("4. Est Triangulaire\n");
		printf ("5. Sortir\n");
		printf ("\n");
		printf ("Veuillez entrer votre selection: ");

        scanf("%d", &choix);
		printf ("\n");	// saut de ligne... formatage seulement
		switch (choix)
		{
		   case CONVERSION_F_EN_C: 
		           //Premier test
		           printf("\nPremier test\n");
                   conversion_f_en_c(45);

		           //Deuxieme test
		           printf("\nDeuxieme test\n");		           
                   conversion_f_en_c(0);

		           //Troisieme test
		           printf("\nTroisieme test\n");		           
                   conversion_f_en_c(-25);
                break;
                
			
           case INVERSER:
		           //Premier test
	               inverser_chaine(chaine1, chaine_retournee);
	               printf("Originale: %s\n", chaine1);
	               printf("Inversee:  %s\n", chaine_retournee);

		           //Premier test
	               inverser_chaine(chaine2, chaine_retournee);
	               printf("Originale: %s\n", chaine2);
	               printf("Inversee:  %s\n", chaine_retournee);
		        break;							

           case PLONGEURS: 
                   //Premier test
                   le_vainqueur = vainqueur(juge1, juge2, juge3);
                   printf("Le vainqueur est a la position: %d\n", le_vainqueur);
		        break;
 
           case EST_TRIANGULAIRE:
                  //Premier test
                  resultat = est_triangulaire_superieure(matrice1);
                  if (resultat==1)
                     printf ("La matrice est triangulaire superieure\n"); 
                  else
                     printf ("La matrice n'est pas triangulaire superieure\n");

                  //Deuxieme test
                  resultat = est_triangulaire_superieure(matrice2);
                  if (resultat==1)
                      printf("La matrice est triangulaire superieure\n");
                  else
                      printf ("La matrice n'est pas triangulaire superieure\n");




		        break;		
		                         
           case SORTIR:
			    return 0;
			    break;			

		default:
			printf ( "Choix invalide!\n");
			printf ( "Veuillez entrer une valeure entre 1 et 5 correspondant a votre choix.\n");
			printf ( "\n");
		}

	}
	return 0;
}			

