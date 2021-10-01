#ifndef __WORD_GAME__
#define __WORD_GAME__

#include <string>
using namespace std;

class Player;

class WordGame {
private:
    string title;
    string startWord;
    int nPlayers;
    Player *players;
    bool createPlayers();
public:
    WordGame(string title, string startWord);
    void run();
    ~WordGame();
};

#endif