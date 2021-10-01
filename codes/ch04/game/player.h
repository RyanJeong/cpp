#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

using namespace std;

class Player {
    string name; // 게임 참가자의 이름
    string word; // 참가자가 말한 단어
public:
    void setName(string name) { this->name=name; }
    string getName(void) { return name; }
    string sayWord(void);
    bool succeed(string lastWord);
};

#endif