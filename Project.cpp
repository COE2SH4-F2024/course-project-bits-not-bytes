#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

Player * myPlayer; //global POINTER to instantiated a player on the heap
GameMechs *myGameMech; //global POINTER to instantiated gameMECH


bool exitFlag;
bool foodGenerated;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGameMech = new GameMechs(35,15);
    myPlayer = new Player(myGameMech);
    
    exitFlag = false;
    foodGenerated = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar()==1)
    {
        myGameMech->setInput(MacUILib_getChar());
    }

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

}
int counter=0;
void DrawScreen(void)
{
    MacUILib_clearScreen();    

    objPosArrayList* playerPos = myPlayer -> getPlayerPos();
    if(foodGenerated == false){
        myGameMech -> generateFood(playerPos);
        myPlayer -> longertail();
        foodGenerated = true;
    }
    objPos foodPos = myGameMech -> getFoodPos();

    int y;
    int x;

    MacUILib_printf("%d and %d, counter %d, and exit: %d\n", foodPos.pos->x, foodPos.pos->y,counter,myGameMech -> getExitFlagStatus());
    counter++;
    int ylength = myGameMech->getBoardSizeY();
    int xlength = myGameMech->getBoardSizeX();

    
    

    for (y=0; y<ylength;y++){

        for (x=0; x<xlength;x++){
            if (myPlayer -> doesCordExist(x,y) != -1){
                int arrayindex = myPlayer -> doesCordExist(x,y);
                MacUILib_printf("%c",playerPos->getElement(arrayindex).symbol);
                continue;
            }

            if (y==0 || y==ylength-1 || x ==0 || x ==xlength-1){
                MacUILib_printf("#");
                continue;
            }

            if(x== foodPos.pos->x && y==foodPos.pos->y){
                MacUILib_printf("%c", foodPos.symbol);
                continue;
            }

            if(playerPos->getHeadElement().pos->x == foodPos.pos->x && playerPos->getHeadElement().pos->y == foodPos.pos->y){
                foodGenerated = false;
            }
            MacUILib_printf(" ");
            int boolcon=0;
            int i,j;

           

            }
        MacUILib_printf("\n");
        }

        MacUILib_printf("%d and %d, counter %d, and exit: %d\n", foodPos.pos->x, foodPos.pos->y,counter,myGameMech -> getExitFlagStatus());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myGameMech;

    MacUILib_uninit();
}
