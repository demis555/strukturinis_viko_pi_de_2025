// ketvirta uzduotis
#include <iostream>
using namespace std;
int main() {

    int EgzamIvert;
    cout << "Ivesti skaiciu:" << endl;
    cin >> EgzamIvert;
    switch (EgzamIvert) {
        case 10:
            cout << "Puiku" << endl;
            break;
        case 9:
            cout << "Labai gera" << endl;
            break;
        case 8:
            cout << "Gerai" << endl;
            break;
        case 7:
            cout << "Gerai" << endl;
            break;
        case 6:
            cout << "Patenkinamai" << endl;
            break;
        case 5:
            cout << "Patenkinamai" << endl;
            break;
        case 4:
            cout << "Egzaminas neislaikytas" << endl;
            break;
        case 3:
            cout << "Egzaminas neislaikytas" << endl;
            break;
        case 2:
            cout << "Egzaminas neislaikytas" << endl;
            break;
        case 1:
            cout << "Egzaminas neislaikytas" << endl;
            break;
        case 0:
            cout << "Egzaminas neislaikytas" << endl;
            break;
        default:
            cout << "Netinkamas skaicius" << endl;
    }
    return 0;
}