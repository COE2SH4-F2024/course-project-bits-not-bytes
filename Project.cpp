#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

Player * myPlayer; //global POINTER to instantiated a player on the heap
GameMechs *myGameMech; //global POINTER to instantiated gameMECH


bool exitFlag;

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

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    objPos playerPos = myPlayer -> getPlayerPos();
    myGameMech -> generateFood(playerPos);
    objPos foodPos = myGameMech -> getFoodPos();

    int y;
    int x;

    MacUILib_clearScreen();
    int ylength = myGameMech->getBoardSizeY();
    int xlength = myGameMech->getBoardSizeX();

    // MacUILib_printf("%c,%d,%d", foodPos.symbol, foodPos.pos->x, foodPos.pos->y);
    // MacUILib_printf("%c, %d, %d",playerPos.symbol, playerPos.pos->x,playerPos.pos->y);
    for (y=0; y<ylength;y++){

        for (x=0; x<xlength;x++){
            if (x == playerPos.pos->x && y== playerPos.pos->y){
                MacUILib_printf("%c",playerPos.symbol);
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

            MacUILib_printf(" ");
            int boolcon=0;
            int i,j;

            // for(i=0;i<5;i++){
            //     if (itemAll[i].x==x&&itemAll[i].y==y){
            //         MacUILib_printf("%c",itemAll[i].symbol);
            //         boolcon=0;
            //         break;
            //     }
            //     if (itemAll[i].x==objectPosition.x && itemAll[i].y==objectPosition.y){
            //         for (j=0;j<my_strlen(endingString);j++){
            //             if(itemAll[i].symbol == endingString[j]){
            //                 stringUnknown[j] = endingString[j];
            //             }
            //         }

            //         // GenerateItems(itemAll, 5, &objectPosition, 19, 9, endingString);
            //         // if (my_strcmp(stringUnknown,endingString) == 1){
            //         //     winDone = 1;
            //         // }
            //     }
            // }

            // if (boolcon){
            //     MacUILib_printf(" ");

            // }


            }
        MacUILib_printf("\n");
        }
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
