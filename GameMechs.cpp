#include "GameMechs.h"

GameMechs::GameMechs()
{
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{

}

bool GameMechs::getLoseFlagStatus() const
{

}
    

char GameMechs::getInput() const
{

}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
}

int GameMechs::getBoardSizeX() const
{

}

int GameMechs::getBoardSizeY() const
{

}


void GameMechs::setExitTrue()
{

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here
void GameMechs::generateFood(objPos blockOff)
{
    int validPos = 1;
    int validChar = 1;
    int candidateX = rand() % boardSizeX;
    int candidateY = rand() % boardSizeY;
    char candidateSymbol = '*';
    
    foodPos.setObjPos(candidateX, candidateY, candidateSymbol); 
    objPos playerPos = blockOff.getObjPos();
    
    if foodPos
    
    validPos = 0;
    }
    
    
}

objPos GameMechs::getFoodPos()
{
    return foodPos;
}