#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{


    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{

    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //nope cuz global variable
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;

}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{   
    return score;

}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;   
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here
void GameMechs::generateFood(objPosArrayList* blockOff)
{
    int validPos = 0;
    int candidateX;
    int candidateY;
    
    int snakeSize = blockOff->getSize();
    
    while(validPos != 1)
    {
        candidateX = rand() % boardSizeX;
        candidateY = rand() % boardSizeY;

        validPos = 1;

        for(int i=0; i<snakeSize; i++)
        {
            objPos bodyElement = blockOff->getElement(i);
            if(candidateX == bodyElement.pos->x && candidateY == bodyElement.pos->y)
            {
                validPos = 0;
                break;
            }
        }

            if (candidateX == 0 || candidateX == boardSizeX - 1 || candidateY == 0 || candidateY == boardSizeY - 1) 
            {
                validPos = 0;
            }

    }  

    food.setObjPos(candidateX, candidateY, '*'); 
}

objPos const GameMechs::getFoodPos()
{
    return food;
}