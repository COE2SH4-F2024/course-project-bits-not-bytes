#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
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
void GameMechs::generateFood(objPos blockOff)
{
    int validPos = 0;
    int candidateX = rand() % boardSizeX;
    int candidateY = rand() % boardSizeY;
    
    objPos playerPos = blockOff.getObjPos();
    
    while(validPos != 1)
    {
        int candidateX = rand() % boardSizeX;
        int candidateY = rand() % boardSizeY;
        

        if(food.pos->x != playerPos.pos->x && food.pos->y != playerPos.pos->y)
        {
            validPos = 1;
            break;
        }
    }  

    food.setObjPos(candidateX, candidateY, '*'); 
}

objPos const GameMechs::getFoodPos()
{
    return food;
}