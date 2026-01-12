#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int game(int maxnum);

int main() {
    srand(time(NULL));

    int maxnum = 40;
    int arvaustenmaara = game(maxnum);



    cout << "Arvausten maara: " << arvaustenmaara << endl;

    return 0;
}

int game(int maxnum) {
    int arvottu = rand() % maxnum + 1;
    int arvaus;
    int laskuri = 0;

    while (true) {
        cout << "Arvaa luku (1-" << maxnum << "): ";
        cin >> arvaus;

        laskuri++;

        if (arvaus < arvottu) {
            cout << "Luku on suurempi." << endl;
        } else if (arvaus > arvottu) {
            cout << "Luku on pienempi." << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
            break;
        }
    }

    return laskuri;
}
