#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

int main() {

    vector<Student> students;

    int choice;

    do {
        cout << "\n0 = Lopeta\n";
        cout << "1 = Lisaa opiskelija\n";
        cout << "2 = Tulosta kaikki\n";
        cout << "3 = Jarjesta ian mukaan\n";
        cout << "4 = Poista opiskelija ID:lla\n";
        cout << "Valinta: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            int id, age;
            string name;

            cout << "Anna ID: ";
            cin >> id;

            cout << "Anna nimi: ";
            cin >> name;

            cout << "Anna ika: ";
            cin >> age;

            students.push_back(Student(id, name, age));
            break;
        }

        case 2: {
            // iteraattorin kaytto
            for (vector<Student>::iterator it = students.begin();
                 it != students.end(); ++it) {
                it->print();
            }
            break;
        }

        case 3: {
            // algoritmin kaytto
            sort(students.begin(), students.end(),
                 [](Student a, Student b) {
                     return a.getAge() < b.getAge();
                 });

            cout << "Jarjestetty ian mukaan.\n";
            break;
        }

        case 4: {
            int removeId;
            cout << "Anna poistettava ID: ";
            cin >> removeId;

            students.erase(
                remove_if(students.begin(), students.end(),
                          [removeId](Student s) {
                              return s.getId() == removeId;
                          }),
                students.end());

            break;
        }

        }

    } while(choice != 0);

    return 0;
}
