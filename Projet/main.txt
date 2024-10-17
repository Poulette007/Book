// refactor doc (method PasclaCase)
#include <Arduino.h>
#include <stdio.h>
#include "librobus.h"
#include "myFunction.h"

#define PULSES_PER_BLOCK 6685
#define PULSES_PER_TURN 2075

#define TAILLE_MAX_DU_PARCOURS 15

#define NOMBRE_DE_PARCOURS 3

int parcours[NOMBRE_DE_PARCOURS * 2][TAILLE_MAX_DU_PARCOURS] =
    //      x                                            y
    {{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2}, {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9}, 
     {1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, -1, -1}, {0, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, -1, -1}, 
    {1, 2, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2}, {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9}};

// int currentParcourX[TAILLE_MAX_DU_PARCOURS] = parcours[0];
// int currentParoursY[TAILLE_MAX_DU_PARCOURS] = parcours[1];
int currentParcourX[TAILLE_MAX_DU_PARCOURS] = {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2};
int currentParoursY[TAILLE_MAX_DU_PARCOURS] = {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9};

int possibleParcour[3] = {1, 2, 3};
int currentParcour = 1;

int robotX = 1;
int robotY = 0;
int robotAngle = 0;
int currentIndex = 0;
void setup()
{
  BoardInit();
}
void loop()
{
  SOFT_TIMER_Update();
//  if(ROBUS_IsBumper(3))
    if (currentIndex < TAILLE_MAX_DU_PARCOURS)
    {
      //startFromI(findIFromPos(robotX, robotY), currentParcourX, currentParoursY);
      currentIndex++;
      moveOneBlockForward(1);
      delay(10);
    }
 

  // Serial.println(IsWall());

  }
/*void perfectTurnLeft();
void perfectTurnRight();
void moveOneBlockForward(int firstMotor);
void dualMotorRatio(float speed, int maxPulses, int firstMotor);
int findIFromPos(int x, int y);
bool IsWall();
int arr_length(int parkour[]);
void stopAll();
void dualMotorSpeed(float speedLeft, float speedRight, int maxPulses);
void startFromI(int pos, int parcourX[], int parcourY[]);
void ChangeParours();

// int numberOfPossiblePath = 6;
#define PULSES_PER_BLOCK 6685
#define PULSES_PER_TURN 2075

#define TAILLE_MAX_DU_PARCOURS 15

#define NOMBRE_DE_PARCOURS 3

int parcours[NOMBRE_DE_PARCOURS * 2][TAILLE_MAX_DU_PARCOURS] =
    // x                                            //y
    {{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2}, {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9},
     {1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, -1, -1}, {0, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, -1, -1},
     {1, 2, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2}, {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9}};

// int currentParcourX[TAILLE_MAX_DU_PARCOURS] = parcours[0];
// int currentParoursY[TAILLE_MAX_DU_PARCOURS] = parcours[1];
int currentParcourX[TAILLE_MAX_DU_PARCOURS] = {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2};
int currentParoursY[TAILLE_MAX_DU_PARCOURS] = {0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9};

int possibleParcour[3] = {1, 2, 3};
int currentParcour = 1;

int robotX = 1;
int robotY = 0;
int robotAngle = 0;
int currentIndex = 0;
*/
/*
void dualMotorRatio(float speed, int maxPulses, int firstMotor) {
    bool isDone = false;
    float speedLeft = speed * 0.985;
    float speedRight = speed;

    while(!isDone) {
        if (abs(ENCODER_Read(0)) > maxPulses && abs(ENCODER_Read(1)) > maxPulses) {
            ENCODER_Reset(0);
            ENCODER_Reset(1);
            isDone = true;
        }

//        if(abs(ENCODER_Read(0)) > abs(ENCODER_Read(1))) {
//            speedLeft = speedLeft * 0.999;
//            Serial.println(speedLeft);
//        }
//        if(abs(ENCODER_Read(0)) < abs(ENCODER_Read(1))) {
//            speedLeft = speedLeft * 1.001;
//            Serial.println(speedLeft);
//        }

        if(firstMotor == 0) {
            if(abs(ENCODER_Read(0)) <= maxPulses) {
                MOTOR_SetSpeed(0, speedLeft);
            } else {
                MOTOR_SetSpeed(0, 0);
            }
            if(abs(ENCODER_Read(1)) <= maxPulses) {
                MOTOR_SetSpeed(1, speedRight);
            } else {
                MOTOR_SetSpeed(1, 0);
            }
        }

        if(firstMotor == 1) {
            if(abs(ENCODER_Read(1)) <= maxPulses) {
                MOTOR_SetSpeed(1, speedRight);
            } else {
                MOTOR_SetSpeed(1, 0);
            }
            if(abs(ENCODER_Read(0)) <= maxPulses) {
                MOTOR_SetSpeed(0, speedLeft);
            } else {
                MOTOR_SetSpeed(0, 0);
            }
        }
    }
}


bool IsWall()
{
  bool verif;
  if (analogRead(A1) < 500 && analogRead(A0) < 500) {
    verif = true;
  } else {
    verif = false;
  }
  return verif;
}
int arr_length(int parkour[])
{
  int i;
  int count = 0;
  for (i = 0; parkour[i] != '\0'; i++)
  {
    count++;
  }
  return count;
}
void stopAll()
{
  MOTOR_SetSpeed(0, 0);
  MOTOR_SetSpeed(1, 0);
}
void dualMotorSpeed(float speedLeft, float speedRight, int maxPulses)
{
  bool isDone = false;

  while (!isDone)
  {
    if (abs(ENCODER_Read(0)) > maxPulses && abs(ENCODER_Read(1)) > maxPulses)
    {
      ENCODER_Reset(0);
      ENCODER_Reset(1);
      isDone = true;
    }
    if (abs(ENCODER_Read(0)) <= maxPulses)
    {
      MOTOR_SetSpeed(0, speedLeft);
    }
    else
    {
      MOTOR_SetSpeed(0, 0);
    }
    if (abs(ENCODER_Read(1)) <= maxPulses)
    {
      MOTOR_SetSpeed(1, speedRight);
    }
    else
    {
      MOTOR_SetSpeed(1, 0);
    }
  }
}
void perfectTurnLeft()
{
  dualMotorSpeed(-0.25, -0.25, 250);
  dualMotorSpeed(-0.25, 0.25, 2075);
  dualMotorSpeed(0.25, 0.25, 375);
  stopAll();
  robotAngle = 270;
}

void perfectTurnRight()
{
  dualMotorSpeed(-0.25, -0.25, 250);
  dualMotorSpeed(0.25, -0.25, 2100);
  dualMotorSpeed(0.25, 0.25, 375);
  stopAll();
  robotAngle = 90;
}



int findIFromPos(int x, int y)
{
  for (int i = 0; i < TAILLE_MAX_DU_PARCOURS; i++)
  {
    if (currentParcourX[i] == x && currentParoursY[i] == y)
    {
      return i;
    }
  }
  return -1;
}
void moveOneBlockForward(int firstMotor)
{
  if (!IsWall())
  {
    dualMotorSpeed(0.25, PULSES_PER_BLOCK, firstMotor);
    stopAll();
  }
  else{
    if (robotAngle == 270)
      perfectTurnRight();
    else if (robotAngle == 90)
      perfectTurnLeft();
    robotAngle = 0;
    ChangeParours();
  }
}
void startFromI(int pos, int parcourX[], int parcourY[])
{
  // for (int i = pos; i < 15; ++i) {
  Serial.println("Moving to block ");
  int x = parcourX[pos + 1];
  // if (currentIndex != 0) {
  if (robotX == x && robotAngle == 0)
  {
    moveOneBlockForward(1);
    robotAngle = 0;
  }
  else if (robotX == x && robotAngle == 270)
  {
    perfectTurnRight();
    moveOneBlockForward(1);
    robotAngle = 0;
  }
  else if (robotX == x && robotAngle == 90)
  {
    perfectTurnLeft();
    moveOneBlockForward(1);
    robotAngle = 0;
  }
  else if (x == robotX - 1 && robotAngle == 270)
  {
    moveOneBlockForward(1);
    robotAngle = 270;
  }
  else if (x == robotX - 1 && robotAngle == 90)
  {
    moveOneBlockForward(1);
    robotAngle = 90;
  }
  else if (x == robotX - 1)
  {
    perfectTurnLeft();
    moveOneBlockForward(1);
    robotAngle = 270;
  }
  else if (x == robotX + 1)
  {
    perfectTurnRight();
    moveOneBlockForward(1);
    robotAngle = 90;
  }
  robotX = x;
  robotY = parcourY[pos + 1];
}

void ChangeParours()
{
  bool parcourChange = false;
  int id = findIFromPos(robotX, robotY);
  Serial.println("my position");
  if (robotY <= 0)
  {
    for (int i = 0; i < NOMBRE_DE_PARCOURS; i++)
    {
      if (parcours[i * 2][1] == currentParcourX[1])
      {
        possibleParcour[i] = -1;
      }
    }

    startFromI(-1, currentParcourX, currentParoursY);
    Serial.println("come back to index (1, 0)");
    possibleParcour[currentParcour - 1] = -1;

    for (int i = 0; i < NOMBRE_DE_PARCOURS; i++)
    {
      if (possibleParcour[i] != -1)
      {
        for (int k = 0; k < TAILLE_MAX_DU_PARCOURS; k++)
        {
          currentParcourX[k] = parcours[NOMBRE_DE_PARCOURS * 2][k];
          currentParoursY[k] = parcours[NOMBRE_DE_PARCOURS * 2 + 1][k];
        }
        currentParcour == i + 1;
        return;
      }
    }
  }
  else
  {
    bool isPathPossible = true;
    possibleParcour[currentParcour - 1] = -1;
    Serial.println("y > 0");
    for (int i = 0; i < NOMBRE_DE_PARCOURS; i++)
    {
      isPathPossible = true;
      if (possibleParcour[i] != -1)
      {
        for (int j = 0; j <= id; j++)
        {
          if (parcours[i * 2][j] != currentParcourX[j])
          {
            possibleParcour[i] = -1;
            isPathPossible = false;
          }
          if (j == id && parcourChange == false && isPathPossible)
          {
            currentParcour = i + 1;
            parcourChange = true;
            for (int k = 0; k < TAILLE_MAX_DU_PARCOURS; k++)
            {
              currentParcourX[k] = parcours[i * 2][k];
              currentParoursY[k] = parcours[i * 2 + 1][k];
            }
          }
        }
      }
    }
  }
}
*/
