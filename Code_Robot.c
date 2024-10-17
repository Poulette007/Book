#include <stdio.h>

#define nombreDeParcours 3
#define tailleDuParcours 7

// const

                            
    int Parcours[tailleMaxDuParcours][NOMBRE_DE_PARCOURS * 2] =    
    //x                 //y
    {{0,1,1,2,2,3,4},   {0,1,1,0,0,1,1},
    {0,1,1,2,2,3,4},    {0,1,1,0,0,1,1},
    {0,1,1,2,2,3,4},    {0,1,1,0,0,1,1}};
    
    int id = 0;
    int  CapteurMure = 0;
void changeParours(int currentParcourX[tailleMaxDuParcours], int currentParoursY[tailleMaxDuParcours]);
int main()
{
    int currentParcourX[tailleMaxDuParcours];
    int currentParoursY[tailleMaxDuParcours];    
    for (int k = 0; k < tailleMaxDuParcours; k++) {
                    currentParcourX[k] = Parcours[0][k];
                    currentParoursY[k] = Parcours[1][k];
                }  
    
    // logique de deplacement :
    if (CapteurMure == 1) {} 
    changeDeParcour(currentParcourX, currentParoursY);
    if (id == tailleMaxDuParcours + 1) {} 
        // parcour fini
    else if (currentParcourX[id] == currentParcourX[id]) {}
        //move up
    else if(currentParcourX[id] < currentParcourX[id + 1]) {}
        // go right
    else if(currentParcourX[id] < currentParcourX[id + 1]) {}
        //go left
    
    
    
    for (int i = 0; i < 6; i++)
        printf("x: %d y: %d\n", currentParcourX[i], currentParoursY[i]);
    
    return 0;
}

void changeParours(int currentParcourX[tailleMaxDuParcours], int currentParoursY[tailleMaxDuParcours])
{
    if(id == 0) {
        return;
    } // just change   
    
    for (int i = 0; i < NOMBRE_DE_PARCOURS; i++)
    {
        for (int j = 0; j <= id; j++)
        {
            if (Parcours[i*2][j] != currentParcourX[j])
            {
                break;
            }
            if (j == id)
            {
                for (int k = 0; k < tailleMaxDuParcours; k++) {
                    currentParcourX[k] = Parcours[i * 2][k];
                    currentParoursY[k] = Parcours[i * 2 + 1][k];
                }  
            }
        }
    }
}


