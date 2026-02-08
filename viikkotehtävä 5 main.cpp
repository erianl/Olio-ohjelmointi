#include <iostream>
#include <string>

using namespace std;

// ---- Seuraaja ----
class Seuraaja {
    string nimi;

public:
    Seuraaja* next;

    Seuraaja(string n) {
        nimi = n;
        next = nullptr;
    }

    string getNimi() {
        return nimi;
    }

    void paivitys(string viesti) {
        cout << nimi << " sai viestin: " << viesti << endl;
    }
};

// ---- Notifikaattori ----
class Notifikaattori {
    Seuraaja* seuraajat;

public:
    Notifikaattori() {
        seuraajat = nullptr;
    }

    void lisaa(Seuraaja* s) {
        s->next = seuraajat;
        seuraajat = s;
    }

    void poista(Seuraaja* s) {
        if (seuraajat == s) {
            seuraajat = s->next;
            return;
        }

        Seuraaja* tmp = seuraajat;
        while (tmp->next != nullptr) {
            if (tmp->next == s) {
                tmp->next = s->next;
                return;
            }
            tmp = tmp->next;
        }
    }

    void tulosta() {
        Seuraaja* tmp = seuraajat;
        while (tmp != nullptr) {
            cout << tmp->getNimi() << endl;
            tmp = tmp->next;
        }
    }

    void postita(string viesti) {
        Seuraaja* tmp = seuraajat;
        while (tmp != nullptr) {
            tmp->paivitys(viesti);
            tmp = tmp->next;
        }
    }
};

// ---- main ----
int main() {
    Seuraaja s1("Matti");
    Seuraaja s2("Teppo");
    Seuraaja s3("Laura");

    Notifikaattori n;

    n.lisaa(&s1);
    n.lisaa(&s2);
    n.lisaa(&s3);

    cout << "Seuraajat:" << endl;
    n.tulosta();

    cout << "\nPostitus:" << endl;
    n.postita("Moi kaikille");

    n.poista(&s2);

    cout << "\nPoiston jalkeen:" << endl;
    n.tulosta();

    return 0;
}
