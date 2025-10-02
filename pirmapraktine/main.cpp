//Pirma praktine uzduotis
//Demianas Gulidovas PI25
#include <iostream>
#include <iomanip>
using namespace std;

void Palyginti();
void Isigyti();
void Parduoti();
void Pasirinkimai();
double GBP_Bendras   = 0.8729;
double GBP_Pirkti    = 0.8600;
double GBP_Parduoti  = 0.9220;
double USD_Bendras   = 1.1793;
double USD_Pirkti    = 1.1460;
double USD_Parduoti  = 1.2340;
double INR_Bendras   = 104.6918;
double INR_Pirkti    = 101.3862;
double INR_Parduoti  = 107.8546;
int main() {
    int pasirinkimas;
    cout << "1. Valiutu palyginimas" << endl; 
    cout << "2. Isigyti valiuta" << endl;
    cout << "3. parduoti valiuta" << endl;
    cin >> pasirinkimas;
    switch (pasirinkimas) {
        case 1: {
            Palyginti();
            break;
        }
        case 2: {
            Isigyti();
            break;
        }
        case 3: {
            Parduoti();
            break;
        }
        default: cout << "Nera tokio pasirinkimo." << endl;
    }

    return 0;
}
void Pasirinkimai(){
    int pasirinkimas;
    cout << "Testi Pasirinkimus? [y/n]" << endl;
    char YorN; 
    cin >> YorN;
    if (YorN == 'N' || YorN == 'n') {
        cout << "iseijimas..." << endl;
        exit(0);
    }
    else if (YorN == 'Y' || YorN == 'y') {
        cout << "Tesiame..." << endl;
    }
    else{
        cout <<"Tokio pasirinkimo nera..." << endl;
        exit(0);
    }
    cout << "1. Valiutu palyginimas" << endl; 
    cout << "2. Isigyti valiuta" << endl;
    cout << "3. parduoti valiuta" << endl;
    cin >> pasirinkimas;
    switch (pasirinkimas) {
        case 1: {
            Palyginti();
            break;
        }
        case 2: {
            Isigyti();
            break;
        }
        case 3: {
            Parduoti();
            break;
        }
        default: cout << "Nera tokio pasirinkimo." << endl;
    }
}

void Palyginti() {
    cout << "Palyginti valiutos kursa su kita valiuta" << endl;
    cout << "Galimi valiutos kursu palyginimai" << endl;
    cout << "1. EUR su GBP" << endl;
    cout << "2. EUR su USD" << endl;
    cout << "3. EUR su INR" << endl;
    int kursas;
    cin >> kursas;
    double kiekis;
    switch (kursas) {
        case 1: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURtoGBP = kiekis * GBP_Bendras;
            cout << "EUR palygintas su GBP: " << fixed << setprecision(3) << EURtoGBP << endl;
            Pasirinkimai();
        }
        case 2: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURtoUSD = kiekis * USD_Bendras;
            cout << "EUR palygintas su USD: " << fixed << setprecision(3) << EURtoUSD << endl;
            Pasirinkimai();
        }
        case 3: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURtoINR = kiekis * INR_Bendras;
            cout << "EUR palygintas su INR: " << fixed << setprecision(3) << EURtoINR << endl;
            Pasirinkimai();
        }
        default: cout << "Nera tokio pasirinkimo." << endl;
    }
}
void Isigyti(){

    cout << "Kokia valiuta norite isigyti? (EUR pagrindas)" << endl;
    cout << "1. GBP" << endl;
    cout << "2. USD" << endl;
    cout << "3. INR" << endl;
    int isigytisuEur;
    cin >> isigytisuEur;
    double kiekis;
    switch (isigytisuEur){
        case 1: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURexchangeGBP = kiekis * GBP_Pirkti;
            cout << "Nupirkta GBP: " << fixed << setprecision(3) << EURexchangeGBP << endl;
            Pasirinkimai();
        }
        case 2: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURexchangeUSD = kiekis * USD_Pirkti;
            cout << "Nupirkta USD: " << fixed << setprecision(3) << EURexchangeUSD << endl;
            Pasirinkimai();
        }
        case 3: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURexchangeINR = kiekis * INR_Pirkti;
            cout << "Nupirkta INR: " << fixed << setprecision(3) << EURexchangeINR << endl;
            Pasirinkimai();
        }
        default: cout << "Nera tokio pasirinkimo." << endl;
    }
} 
void Parduoti(){

    cout << "Kokia valiuta norite parduoti? (EUR pagrindas)" << endl;
    cout << "1. GBP" << endl;
    cout << "2. USD" << endl;
    cout << "3. INR" << endl;
    int parduotival;
    cin >> parduotival;
    double kiekis;
    switch (parduotival){
        case 1: {
            cout << "GBP kiekis: " << endl;
            cin >> kiekis;
            double GBPtoEUR = kiekis / GBP_Parduoti;
            cout << "Parduota GBP: " << fixed << setprecision(3) << GBPtoEUR << endl;
            Pasirinkimai();
        }
        case 2: {
            cout << "USD kiekis: " << endl;
            cin >> kiekis;
            double USDtoEUR = kiekis / USD_Parduoti;
            cout << "Parduota USD: " << fixed << setprecision(3) << USDtoEUR << endl;
            Pasirinkimai();
        }
        case 3: {
            cout << "INR kiekis: " << endl;
            cin >> kiekis;
            double INRtoEUR = kiekis / INR_Parduoti;
            cout << "Parduota INR: " << fixed << setprecision(3) << INRtoEUR << endl;
            Pasirinkimai();
        }
        default: cout << "Nera tokio pasirinkimo." << endl;
    }
}

