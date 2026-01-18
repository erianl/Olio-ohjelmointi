#include "olio1.h"
#include <iostream>
using namespace std;

GameNew::GameNew(int mN)
{
    cout << "Peli luotu " << endl;
    maxNumber = mN;
}

GameNew::~GameNew()
{
    cout << "Peli tuhottu " << endl;
}

void GameNew::play()
{
    cout << "Pelissa " << endl;

    srand(time(NULL));
    randomNumber = (rand() % maxNumber)+1;

    while (playerGuess != randomNumber) {
        cout << "Anna arvaus? " << endl;
        cin >> playerGuess;

        numOfGuesses++;


        if (playerGuess == randomNumber) {
            cout << "Oikein!!" << endl;
        } else if (playerGuess < randomNumber){
            cout << "Luku on suurempi!" << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Luku on pienempi!" << endl;
        }
    }

}

void GameNew::printGameResult()
{
    cout << "Tulostuksessa " << endl;
    cout << "Oikea luku: " << randomNumber << endl << "Arvausten maara: " << numOfGuesses << endl;
}


#ifndef GAMENEW_H
#define GAMENEW_H

class GameNew
{
public:
    GameNew(int);
    ~GameNew();
    void play();
    void printGameResult();
private:
    int maxNumber = 0;
    int playerGuess = 0;
    int randomNumber = 0;
    int numOfGuesses = 0;
protected:

};

#endif


#include "gamenew.h"
#include <iostream>

int main(){
    int maxNum(50);
    GameNew peliOlio(maxNum);
    peliOlio.play();
    peliOlio.printGameResult();

    std::cout << "Arvasit oikein" << std::endl;
    return 0;
}
