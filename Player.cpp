#include "Player.h"
#include "objPosArrayList.h"
#include "objPos.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    objPos playerPos = objPos();
    //add the cordinates

    int xlength = mainGameMechsRef->getBoardSizeX();
    int ylength = mainGameMechsRef ->getBoardSizeY();

    playerPos.setObjPos(xlength/2,ylength/2,'@');
    
    playerPosList = new objPosArrayList();
    playerPosList -> insertHead(playerPos);

    myDir = STOP;

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos()  const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic 
    char input = mainGameMechsRef->getInput();


     if(input != 0)  // if not null character
    {
        switch(input)
        {                      

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

    objPos newhead = playerPosList -> getHeadElement();

    if (myDir == RIGHT){
        (newhead.pos -> x)++;
    }
    else if (myDir == LEFT){
        (newhead.pos -> x)--;
    }
    else if (myDir == UP){
        (newhead.pos -> y)--;
    }
    else if (myDir == DOWN){
        (newhead.pos -> y)++;
    }
    // [TODO] : Heed the border wraparound!!!

    int xlength = mainGameMechsRef -> getBoardSizeX();
    int ylength = mainGameMechsRef -> getBoardSizeY();

    if (newhead.pos -> x == xlength-1){
        newhead.pos -> x = 1;
    }
    else if (newhead.pos -> x == 0){
        newhead.pos -> x = xlength-2;
    }

    if (newhead.pos -> y == 0){
        newhead.pos -> y = ylength-2;
    }
    else if (newhead.pos -> y == ylength-1){
        newhead.pos -> y = 1;
    }


    playerPosList -> insertHead(newhead);
    playerPosList -> removeTail();

}

// More methods to be added


int Player::doesCordExist(int xin, int yin) const{

    for (int i=0; i<playerPosList->getSize();i++){
        objPos thisobj = playerPosList->getElement(i);
        if (thisobj.pos->x == xin && thisobj.pos->y == yin){
            return i;
        }
    }

    return -1;

}

void Player::longertail(){
    objPos posA = playerPosList ->getTailElement();
    objPos posB = playerPosList ->getSecondTailElement();

    int x_tail = 2*(posA.pos->x) - (posB.pos->x);
    int y_tail = 2*(posA.pos->y) - (posB.pos->y);

    objPos newTail = objPos(x_tail,y_tail,'@');
    
    playerPosList -> insertTail(newTail);

}