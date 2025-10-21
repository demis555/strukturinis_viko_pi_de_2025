#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_MOK = 100;
const int MAX_PAZ = 10;

void rodytiMeniu();
void pridetiMokini(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int& mokiniuSkaicius);
void perziuretiVisus(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int mokiniuSkaicius);
void perziuretiMokini(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int mokiniuSkaicius);
void atnaujintiPazymi(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int mokiniuSkaicius);
void pasalintiMokini(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int& mokiniuSkaicius);
int rastiMokini(string vardai[], int mokiniuSkaicius, string vardas);
double skaiciuotiVidurki(int pazymiai[], int kiekis);

int main() {
    string vardai[MAX_MOK];
    int pazymiai[MAX_MOK][MAX_PAZ];
    int pazymiuKiekis[MAX_MOK] = {0};
    int mokiniuSkaicius = 0;
    int pasirinkimas;

    cout << "=== MOKINIU PAZYMIU VALDYMO SISTEMA ===" << endl << endl;

    do {
        rodytiMeniu();
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;
        cin.ignore();

        cout << endl;

        switch(pasirinkimas) {
            case 1:
                pridetiMokini(vardai, pazymiuKiekis, pazymiai, mokiniuSkaicius);
                break;
            case 2:
                perziuretiVisus(vardai, pazymiuKiekis, pazymiai, mokiniuSkaicius);
                break;
            case 3:
                perziuretiMokini(vardai, pazymiuKiekis, pazymiai, mokiniuSkaicius);
                break;
            case 4:
                atnaujintiPazymi(vardai, pazymiuKiekis, pazymiai, mokiniuSkaicius);
                break;
            case 5:
                pasalintiMokini(vardai, pazymiuKiekis, pazymiai, mokiniuSkaicius);
                break;
            case 0:
                cout << "Programa baigia darba." << endl;
                break;
            default:
                cout << "Neteisingas pasirinkimas, bandykite dar karta." << endl;
        }

        cout << endl;

    } while(pasirinkimas != 0);

    return 0;
}

void rodytiMeniu() {
    cout << "======================================" << endl;
    cout << "MENIU:" << endl;
    cout << "1. Prideti mokini ir jo pazymius" << endl;
    cout << "2. Perziureti visu mokiniu pazymius" << endl;
    cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
    cout << "4. Atnaujinti pazymi" << endl;
    cout << "5. Pasalinti mokini" << endl;
    cout << "0. Iseiti" << endl;
    cout << "======================================" << endl;
}

void pridetiMokini(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int& mokiniuSkaicius) {
    if(mokiniuSkaicius >= MAX_MOK) {
        cout << "Klaida, pasiektas maksimalus mokiniu skaicius (" << MAX_MOK << ")." << endl;
        return;
    }

    string vardas;
    cout << "Iveskite mokinio varda: ";
    getline(cin, vardas);

    // Patikrinti, ar toks mokinys jau egzistuoja
    if(rastiMokini(vardai, mokiniuSkaicius, vardas) != -1) {
        cout << "Klaida, mokinys tokiu vardu jau egzistuoja." << endl;
        return;
    }

    vardai[mokiniuSkaicius] = vardas;

    int kiekis;
    cout << "Kiek pazymiu norite ivesti (max " << MAX_PAZ << ")? ";
    cin >> kiekis;

    if(kiekis < 0 || kiekis > MAX_PAZ) {
        cout << "Klaida, neteisingas pazymiu kiekis." << endl;
        return;
    }

    pazymiuKiekis[mokiniuSkaicius] = kiekis;

    for(int i = 0; i < kiekis; i++) {
        int pazymys;
        do {
            cout << "Iveskite " << (i + 1) << "-aji pazymi (1-10): ";
            cin >> pazymys;

            if(pazymys < 1 || pazymys > 10) {
                cout << "Klaida, pazymys turi buti tarp 1 ir 10." << endl;
            }
        } while(pazymys < 1 || pazymys > 10);

        pazymiai[mokiniuSkaicius][i] = pazymys;
    }

    mokiniuSkaicius++;
    cout << "Mokinys sekmingas pridetas!" << endl;
}

void perziuretiVisus(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int mokiniuSkaicius) {
    if(mokiniuSkaicius == 0) {
        cout << "Sarasas tuscias, nera pridetu mokiniu." << endl;
        return;
    }

    cout << "=== VISU MOKINIU PAZYMIAI ===" << endl << endl;

    for(int i = 0; i < mokiniuSkaicius; i++) {
        cout << "Mokinys: " << vardai[i] << endl;
        cout << "Pazymiai: ";

        if(pazymiuKiekis[i] == 0) {
            cout << "Nera pazymiu";
        } else {
            for(int j = 0; j < pazymiuKiekis[i]; j++) {
                cout << pazymiai[i][j];
                if(j < pazymiuKiekis[i] - 1) {
                    cout << ", ";
                }
            }
            double vidurkis = skaiciuotiVidurki(pazymiai[i], pazymiuKiekis[i]);
            cout << " | Vidurkis: " << fixed << setprecision(2) << vidurkis;
        }

        cout << endl << endl;
    }
}

void perziuretiMokini(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int mokiniuSkaicius) {
    if(mokiniuSkaicius == 0) {
        cout << "Sarasas tuscias, nera pridetu mokiniu." << endl;
        return;
    }

    cout << "=== MOKINIU SARASAS ===" << endl << endl;

    for(int i = 0; i < mokiniuSkaicius; i++) {
        cout << (i+1) << ". " << "Mokinys: " << vardai[i] << endl;
    }

    cout << endl << endl;

    string vardas;
    cout << "Iveskite mokinio varda: ";
    getline(cin, vardas);

    int indeksas = rastiMokini(vardai, mokiniuSkaicius, vardas);

    if(indeksas == -1) {
        cout << "Klaida, mokinys nerastas." << endl;
        return;
    }

    cout << endl << "Mokinys: " << vardai[indeksas] << endl;
    cout << "Pazymiai: ";

    if(pazymiuKiekis[indeksas] == 0) {
        cout << "Nera pazymiu";
    } else {
        for(int j = 0; j < pazymiuKiekis[indeksas]; j++) {
            cout << pazymiai[indeksas][j];
            if(j < pazymiuKiekis[indeksas] - 1) {
                cout << ", ";
            }
        }
        double vidurkis = skaiciuotiVidurki(pazymiai[indeksas], pazymiuKiekis[indeksas]);
        cout << endl << "Vidurkis: " << fixed << setprecision(2) << vidurkis;
    }

    cout << endl;
}

void atnaujintiPazymi(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int mokiniuSkaicius) {
    if(mokiniuSkaicius == 0) {
        cout << "Sarasas tuscias, nera pridetu mokiniu." << endl;
        return;
    }

    cout << "=== MOKINIU SARASAS ===" << endl << endl;

    for(int i = 0; i < mokiniuSkaicius; i++) {
        cout << (i+1) << ". " << "Mokinys: " << vardai[i] << endl;
    }

    cout << endl << endl;

    string vardas;
    cout << "Iveskite mokinio varda: ";
    getline(cin, vardas);

    int indeksas = rastiMokini(vardai, mokiniuSkaicius, vardas);

    if(indeksas == -1) {
        cout << "Klaida, mokinys nerastas." << endl;
        return;
    }

    if(pazymiuKiekis[indeksas] == 0) {
        cout << "Klaida, sis mokinys neturi pazymiu." << endl;
        return;
    }

    cout << "Esami pazymiai: ";
    for(int i = 0; i < pazymiuKiekis[indeksas]; i++) {
        cout << (i + 1) << ". " << pazymiai[indeksas][i];
        if(i < pazymiuKiekis[indeksas] - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    int pazymioPozicija;
    cout << "Kuri pazymi norite atnaujinti (1-" << pazymiuKiekis[indeksas] << ")? ";
    cin >> pazymioPozicija;

    if(pazymioPozicija < 1 || pazymioPozicija > pazymiuKiekis[indeksas]) {
        cout << "Klaida, neteisinga pozicija" << endl;
        return;
    }

    int naujsPazymys;
    do {
        cout << "Iveskite nauja pazymi (1-10): ";
        cin >> naujsPazymys;

        if(naujsPazymys < 1 || naujsPazymys > 10) {
            cout << "Klaida, pazymys turi buti tarp 1 ir 10." << endl;
        }
    } while(naujsPazymys < 1 || naujsPazymys > 10);

    pazymiai[indeksas][pazymioPozicija - 1] = naujsPazymys;
    cout << "Pazymys sekmingas atnaujintas." << endl;
}

void pasalintiMokini(string vardai[], int pazymiuKiekis[], int pazymiai[][MAX_PAZ], int& mokiniuSkaicius) {
    if(mokiniuSkaicius == 0) {
        cout << "Sarasas tuscias, nera pridetu mokiniu." << endl;
        return;
    }

    cout << "=== MOKINIU SARASAS ===" << endl << endl;

    for(int i = 0; i < mokiniuSkaicius; i++) {
        cout << (i+1) << ". " << "Mokinys: " << vardai[i] << endl;
    }


    string vardas;
    cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
    getline(cin, vardas);

    int indeksas = rastiMokini(vardai, mokiniuSkaicius, vardas);

    if(indeksas == -1) {
        cout << "Klaida, mokinys nerastas." << endl;
        return;
    }

    for(int i = indeksas; i < mokiniuSkaicius - 1; i++) {
        vardai[i] = vardai[i + 1];
        pazymiuKiekis[i] = pazymiuKiekis[i + 1];

        for(int j = 0; j < MAX_PAZ; j++) {
            pazymiai[i][j] = pazymiai[i + 1][j];
        }
    }

    mokiniuSkaicius--;
    cout << "Mokinys sekmingas pasalintas." << endl;
}

int rastiMokini(string vardai[], int mokiniuSkaicius, string vardas) {
    for(int i = 0; i < mokiniuSkaicius; i++) {
        if(vardai[i] == vardas) {
            return i;
        }
    }
    return -1;
}

double skaiciuotiVidurki(int pazymiai[], int kiekis) {
    if(kiekis == 0) {
        return 0;
    }

    int suma = 0;
    for(int i = 0; i < kiekis; i++) {
        suma += pazymiai[i];
    }

    return static_cast<double>(suma) / kiekis;
}