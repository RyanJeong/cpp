//WIP

#include <iostream>

#include "word_game.h"

using namespace std;

int main(void) 
{
    WordGame *game;
    game = new WordGame("끝말 잇기", "아버지");
    game->run();

    delete game;

    return 0;
}