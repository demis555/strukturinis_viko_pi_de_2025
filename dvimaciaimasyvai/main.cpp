//pirma uzd, studentu pazymiu lentele
#include <iostream>
using namespace std;
int main() {
    int n=8;
    int m=4;
    int pazymiai[8][4];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            switch (j) {
                case 0: {
                    cout << "Iveskite "<<i+1<<" studento pazymi dalykui: istorija" << endl;
                    cin >> pazymiai[i][j];
                    break;
                }
                case 1: {
                    cout << "Iveskite "<<i+1<<" studento pazymi dalykui: matematika" << endl;
                    cin >> pazymiai[i][j];
                    break;
                }
                case 2: {
                    cout << "Iveskite "<<i+1<<" studento pazymi dalykui: informatika" << endl;
                    cin >> pazymiai[i][j];
                    break;
                }
                case 3: {
                    cout << "Iveskite "<<i+1<<" studento pazymi dalykui: anglu kalba" << endl;
                    cin >> pazymiai[i][j];
                    break;
                }
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << pazymiai[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
