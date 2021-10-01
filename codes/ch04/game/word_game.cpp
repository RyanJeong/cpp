#include <iostream>

#include "word_game.h"
#include "player.h"

using namespace std;

WordGame::WordGame(string title, string startWord) {
    this->title = title;
    this->startWord = startWord;
    this->players = NULL;
}

WordGame::~WordGame() {
    if(this->players != NULL)
        delete [] this->players;
}

bool WordGame::createPlayers() {
    int n;
    cout << title << " 게임을 시작합니다" << endl;
    cout << "게임에 참가하는 인원은 몇명입니까?";
    cin >> n;

    if(n < 2) {
        cout << "인원수는 2 이상입니다 " << endl;
        return false;
    }
    nPlayers = n;
    players = new Player[n];
    if(!players)
        return false;

    // 각 참여자의 이름을 입력받아 Player 객체 생성
    string playerName;
    for(int i=0; i<nPlayers; i++) {
        cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
        cin >> playerName;
        players[i].setName(playerName);
    }

    return true;
}

void WordGame::run() {
    if(!createPlayers()) // 참가자 수가 2보다 적4던지 문제가 생긴 경우
        return;

    string lastWord = startWord; 
    cout << "시작하는 단어는 "+lastWord+ "입니다" << endl;
    int next =  0; // 참가자들의 순서대로 증가
    
    // 게임이 끝날 때까지 루프
    while(true) {
        string newWord = players[next].sayWord(); // next 참가자가 단어를 말하도록 한다.
        if(!players[next].succeed(lastWord)) { // next 참가자가 성공하였는지 검사.
            cout << players[next].getName() + "이 졌습니다.";
            break; // 게임을 종료한다.
        }
        next++; // 다음 참가자
        next %= nPlayers; // next가 참가자의 개수보다 많게 증가하는 것을 막는다.
        lastWord = newWord;
    }
}
