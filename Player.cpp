#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    int xlength = mainGameMechsRef->getBoardSizeX();
    int ylength = mainGameMechsRef ->getBoardSizeY();
    playerPos.setObjPos(xlength/2,ylength/2,'@');
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic 
    char input = mainGameMechsRef->getInput();


     if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case 27:  // exit
                mainGameMechsRef->setExitTrue();
                break;

            case 'w':
                if(myDir == DOWN){
                    break;
                }
                myDir = UP;
                break;

            case 'a':
                if (myDir == RIGHT){
                    break;
                }
                myDir = LEFT;
                break;

            case 's':
                if (myDir == UP){
                    break;
                }
                myDir = DOWN;
                break;

            case 'd':
                if (myDir == LEFT){
                    break;
                }
                myDir = RIGHT;
                break;



            // Add more key processing here
            // Add more key processing here
            // Add more key processing here    


            default:
                myDir = STOP;
                break;
        }

        input = 0;

    }


}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic


     // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program


    if (myDir == RIGHT){
        (playerPos.pos -> x)++;
    }
    else if (myDir == LEFT){
        (playerPos.pos -> x)--;
    }
    else if (myDir == UP){
        (playerPos.pos -> y)--;
    }
    else if (myDir == DOWN){
        (playerPos.pos -> y)++;
    }
    // [TODO] : Heed the border wraparound!!!

    int xlength = mainGameMechsRef -> getBoardSizeX();
    int ylength = mainGameMechsRef -> getBoardSizeY();

    if (playerPos.pos -> x == xlength){
        playerPos.pos -> x =1;
    }
    else if (playerPos.pos -> x == 0){
        playerPos.pos -> x = xlength-1;
    }

    if (playerPos.pos -> y == 0){
        playerPos.pos -> y = ylength-1;
    }
    else if (playerPos.pos -> y == ylength){
        playerPos.pos -> y = 1;
    }

}

// More methods to be added