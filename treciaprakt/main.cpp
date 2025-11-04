#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char IvestBiliet[] = "C:\\Users\\deg04\\Documents\\cpp viko\\strukturinis_viko_pi_de_2025\\treciaprakt\\tickets.txt";
const char IvestAtlyg[] = "C:\\Users\\deg04\\Documents\\cpp viko\\strukturinis_viko_pi_de_2025\\treciaprakt\\salary.txt";
const char IsvestBiliet[] = "C:\\Users\\deg04\\Documents\\cpp viko\\strukturinis_viko_pi_de_2025\\treciaprakt\\newtickets.txt";
const char IsvestAtlyg[] = "C:\\Users\\deg04\\Documents\\cpp viko\\strukturinis_viko_pi_de_2025\\treciaprakt\\newsalary.txt";
const int Nmax = 10;

void menu();
void Bilietai(int BilietKain[], int ParduotBiliet[], int n);
void Atlyginimai(string vardas[], string pavarde[], double atlyginimas[], double PadidProc[], int n);

int main() {
    int BilietKain[Nmax];
    int ParduotBiliet[Nmax];
    string vardas[Nmax];
    string pavarde[Nmax];
    double atlyginimas[Nmax];
    double PadidProc[Nmax];
    int pasirink;
    int nBiliet = 0, nAtlyg = 0;

    cout << "================== Duomenu apdorojimo sistema ==================" << endl;

    do {
        menu();
        cout << "Pasirinkite veiksma: ";
        cin >> pasirink;
        cin.ignore();

        switch (pasirink) {
            case 1:
                Bilietai(BilietKain, ParduotBiliet, nBiliet);
                break;
            case 2:
                Atlyginimai(vardas, pavarde, atlyginimas, PadidProc, nAtlyg);
                break;
            case 0:
                cout << "Programa baigta" << endl;
                break;
            default:
                cout << "Netinkamas pasirinkimas" << endl;
        }
        cout << endl;
    } while(pasirink != 0);

    return 0;
}

void menu() {
    cout << endl;
    cout << "MENIU:" << endl;
    cout << "1. Skaiciuoti bilietu pardavimo suma" << endl;
    cout << "2. Atnaujinti darbuotoju atlyginimus pagal padidejimo procenta" << endl;
    cout << "0. Baigti programa" << endl;
    cout << endl;
}

void Bilietai(int BilietKain[], int ParduotBiliet[], int n) {
    ifstream BilietKainFile(IvestBiliet);

    if (!BilietKainFile) {
        cout << "Nepavyko atidaryti failo " << IvestBiliet << endl;
        return;
    }

    int i = 0;
    double bendraSum = 0;

    while (i < Nmax && BilietKainFile >> BilietKain[i] >> ParduotBiliet[i]) {
        i++;
    }
    n = i;

    BilietKainFile.close();
    cout << endl;
    cout << "=== Bilietu pardavimo ataskaita ===" << endl;
    cout << left << setw(20) << "Bilieto kaina (EUR)"
         << setw(20) << "Parduota bilietu"
         << setw(20) << "Suma (EUR)" << endl;
    cout << string(60, '-') << endl;

    for (int j = 0; j < n; j++) {
        double suma = BilietKain[j] * ParduotBiliet[j];
        bendraSum += suma;

        cout << left << setw(20) << BilietKain[j]
             << setw(20) << ParduotBiliet[j]
             << setw(20) << fixed << setprecision(2) << suma << endl;
    }

    cout << string(60, '-') << endl;
    cout << "Bendra pardavimo suma: " << fixed << setprecision(2) << bendraSum << " EUR" << endl;

    //---isvesti i faila---

    ofstream IsvestBilietFile(IsvestBiliet);

    IsvestBilietFile << endl;
    IsvestBilietFile << "=== Bilietu pardavimo ataskaita ===" << endl;
    IsvestBilietFile << left << setw(20) << "Bilieto kaina (EUR)"
         << setw(20) << "Parduota bilietu"
         << setw(20) << "Suma (EUR)" << endl;
    IsvestBilietFile << string(60, '-') << endl;

    for (int j = 0; j < n; j++) {
        double suma = BilietKain[j] * ParduotBiliet[j];
        bendraSum += suma;

        IsvestBilietFile << left << setw(20) << BilietKain[j]
             << setw(20) << ParduotBiliet[j]
             << setw(20) << fixed << setprecision(2) << suma << endl;
    }

    IsvestBilietFile << string(60, '-') << endl;
    IsvestBilietFile << "Bendra pardavimo suma: " << fixed << setprecision(2) << bendraSum << " EUR" << endl;
}

void Atlyginimai(string vardas[], string pavarde[], double atlyginimas[], double PadidProc[], int n) {
    ifstream AtlygFile(IvestAtlyg);

    if (!AtlygFile) {
        cout << "Nepavyko atidaryti failo " << IvestAtlyg << endl;
        return;
    }

    int i = 0;

    while (i < Nmax && AtlygFile >> pavarde[i] >> vardas[i] >> atlyginimas[i] >> PadidProc[i]) {
        i++;
    }
    n = i;

    AtlygFile.close();
    cout << endl;
    cout << "=== Darbuotoju atlyginimo ataskaita ===" << endl;
    cout << left << setw(15) << "Pavarde"
         << setw(15) << "Vardas"
         << setw(20) << "Esamas atlyg. (USD)"
         << setw(20) << "Padidejimo proc. (%)"
         << setw(20) << "Naujas atlyg. (USD)" << endl;
    cout << string(90, '-') << endl;

    for (int j = 0; j < n; j++) {
        double naujasAtlyg = atlyginimas[j] * (1 + PadidProc[j] / 100.0);

        cout << left << setw(15) << pavarde[j]
             << setw(15) << vardas[j]
             << setw(20) << atlyginimas[j]
             << setw(20) << PadidProc[j]
             << setw(20) << naujasAtlyg << endl;
    }
    cout << string(90, '-') << endl;


    //---isvesti i faila---

    ofstream IsvestAtlygFile(IsvestAtlyg);

    IsvestAtlygFile << endl;
    IsvestAtlygFile << "=== Darbuotoju atlyginimo ataskaita ===" << endl;
    IsvestAtlygFile << left << setw(15) << "Pavarde"
         << setw(15) << "Vardas"
         << setw(20) << "Esamas atlyg. (USD)"
         << setw(20) << "Padidejimo proc. (%)"
         << setw(20) << "Naujas atlyg. (USD)" << endl;
    IsvestAtlygFile << string(90, '-') << endl;

    for (int j = 0; j < n; j++) {
        double naujasAtlyg = atlyginimas[j] * (1 + PadidProc[j] / 100.0);

        IsvestAtlygFile << left << setw(15) << pavarde[j]
             << setw(15) << vardas[j]
             << setw(20) << atlyginimas[j]
             << setw(20) << PadidProc[j]
             << setw(20) << naujasAtlyg << endl;
    }
    IsvestAtlygFile << string(90, '-') << endl;
}
