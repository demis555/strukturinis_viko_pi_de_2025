#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MAX = 20;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

menuItemType menuList[MAX];
int kiek = 0;

int uzsakyta[MAX] = {0};

void getData();
void showMenu();
void printCheck();

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    getData();
    showMenu();

    int nr, kiekis;
    while (cout << "užsakymo nnumeris: " && cin >> nr && cout << "kiekis:" && cin >> kiekis) {
        if (nr == 0) break;
        if (nr >= 1 && nr <= kiek && kiekis > 0) {
            uzsakyta[nr-1] += kiekis;
        }
    }

    printCheck();
    return 0;
}

void getData() {
    ifstream f("menu.txt");
    string pirmoeilute;
    getline(f, pirmoeilute);               // praleidžiame antraštę

    kiek = 0;
    string eilute;
    while (getline(f, eilute) && kiek < MAX) {
        if (eilute.empty()) continue;

        // randame kur prasideda kaina (paskutiniai skaičiai)
        int pozicija = eilute.length() - 1;
        while (pozicija >= 0 && (eilute[pozicija] >= '0' && eilute[pozicija] <= '9' || eilute[pozicija] == '.')) {
            pozicija--;
        }
        pozicija++;

        menuList[kiek].menuItem = eilute.substr(0, pozicija);
        menuList[kiek].menuPrice = stod(eilute.substr(pozicija));
        kiek++;
    }
    f.close();
}

void showMenu() {
    cout << "\nPUSRYCIU MENIU:\n\n";
    for (int i = 0; i < kiek; i++) {
        cout << i+1 << ". " << menuList[i].menuItem
             << fixed << setprecision(2) << menuList[i].menuPrice << " EUR\n";
    }
    cout << "\nIveskite numeri ir kieki (pvz. 3 2). Baigti: 0 0\n";
}

void printCheck() {
    ofstream failas("receipt.txt", ios::binary);
    failas << "\xEF\xBB\xBF";  // UTF-8 BOM for file
    double suma = 0;

    cout << "Sveiki atvykę į restoraną „Pavadinimas“\n\n";
    failas << "Sveiki atvykę į restoraną „Pavadinimas“\n\n";

    for (int i = 0; i < kiek; i++) {
        if (uzsakyta[i] > 0) {
            double eil = uzsakyta[i] * menuList[i].menuPrice;
            suma += eil;

            if (uzsakyta[i] == 1) {
                cout << menuList[i].menuItem << "   " << fixed << setprecision(2) << menuList[i].menuPrice << "€\n";
                failas << menuList[i].menuItem << "   " << fixed << setprecision(2) << menuList[i].menuPrice << "€\n";
            } else {
                cout << uzsakyta[i] << "  " << menuList[i].menuItem << "   " << fixed << setprecision(2) << menuList[i].menuPrice << "€\n";
                failas << uzsakyta[i] << "  " << menuList[i].menuItem << "   " << fixed << setprecision(2) << menuList[i].menuPrice << "€\n";
            }
        }
    }

    double pvm = suma * 0.21;
    double viso = suma + pvm;

    cout << "\nMokesčiai (21%)                        " << fixed << setprecision(2) << pvm << "€\n";
    cout << "Galutinė suma                          " << viso << "€\n";

    failas << "\nMokesčiai (21%)                        " << fixed << setprecision(2) << pvm << "€\n";
    failas << "Galutinė suma                          " << viso << "€\n";

    failas.close();
}