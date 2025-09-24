// trecia uzduotis
#include <iostream>
using namespace std;
int main() {

    int EgzamIvert;
    cout << "Ivesti skaiciu:" << endl;
    cin >> EgzamIvert;
    if (EgzamIvert == 10) {
        cout << "Puiku" << endl;
    } else if (EgzamIvert >=9) {
        cout << "Labai gerai" << endl;
    } else if (EgzamIvert >=7) {
        cout << "Gerai" << endl;
    } else if (EgzamIvert >=5) {
        cout << "Patenkinamai" << endl;
    } else if (EgzamIvert <5) {
        cout << "Egzaminas neislaikytas" << endl;
    }
    return 0;
}