#include <iostream>
#include <string>

#include "player.h"

using namespace std;

string Player::sayWord(void) 
{
    cout << name + ">>";
    cin >> word;

    return word;
}
    
// unicode: 2 bytes, UTF-8: 3 bytes
// lastWord와 참가자가 말한 word를 비교하여 끝말잇기가 잘되었는지 판단.
// 성공하였으면 true 리턴
bool Player::succeed(string lastWord) 
{
    int lastIndex = lastWord.length()-2; // 최종 단어의 맨 마지막 문자의 인덱스
    
    // 최종 단어의 맨 마지막 문자와 참가자가 말한 단어의 첫 문자가 같은지 비교
    if(lastWord.at(lastIndex) == word.at(0) &&
        lastWord.at(lastIndex+1) == word.at(1))
        return true;
    else
        return false;
}