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

    myPlayer = new Player(nullptr);

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    objPos playerPos = myPlayer -> getPlayerPos();

    int y;
    int x;

    MacUILib_clearScreen();

    for (y=0; y<10;y++){

        for (x=0; x<20;x++){
            if (x == playerPos.pos->x && y== playerPos.pos->y){
                MacUILib_printf("%c",playerPos.getSymbol());
                continue;
            }

            if (y==0 || y==9 || x ==0 || x ==19){
                MacUILib_printf("#");
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

    MacUILib_uninit();
}
