#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char IvestBiliet[] = "DuomBiliet.txt";
const char IvestAtlyg[] = "DuomAtlyg.txt";
const int Nmax = 10;

void menu();
void Bilietai(int BilietKain[], int ParduotBiliet[]);
void Atlyginimai(string vardas[], string pavarde[], double atlyginimas[], double PadidProc[]);
int main() {
    int BilietKain[Nmax];
    int ParduotBiliet[Nmax];
    string vardas[Nmax];
    string pavarde[Nmax];
    double atlyginimas[Nmax];
    double PadidProc[Nmax];
    int pasirink;

    cout << "================== Duomenu apdorojimo sistema ==================" << endl;

    do {
        menu();
        cout << "Pasirinkite veiksma: ";
        cin >> pasirink;
        cin.ignore();
        switch (pasirink) {
            case 1:
                Bilietai(BilietKain, ParduotBiliet);
                break;
            case 2:
                Atlyginimai(vardas, pavarde, atlyginimas, PadidProc);
                break;
            case 0:
                cout << "programa baigta" << endl;
                break;
            default:
                cout << "Netinkamas pasirinkimas" << endl;
        }
        cout << endl;
    }while(pasirink != 0);

    return 0;
}
void menu() {

    cout << "MENIU:" << endl;
    cout << "1. Skaiciuoti bilietu pardavimo suma" << endl;
    cout << "2. Atnaujinti darbuotoju atlyginimus pagal padidejimo procenta" << endl;
    cout << "0. Baigti programa" << endl;
    cout << endl;
}
void Bilietai(int BilietKain[], int ParduotBiliet[]) {

    ifstream BilietKainFile(IvestBiliet);
    //int n or something here, smh
    //code is useless for now, sadge
    for (int i = 0; i < Nmax; i++) {
        BilietKainFile >> BilietKain[i];
    }

}

void Atlyginimai(string vardas[], string pavarde[], double atlyginimas[], double PadidProc[]) {

}

