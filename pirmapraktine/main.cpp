#include <iostream>
#include <iomanip>
using namespace std;

void Palyginti();
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
    cout << "1. Valiutu palyginimas \n 2. Isigyti valiuta \n 3. parduoti valiuta" << endl;
    cin >> pasirinkimas;
    switch (pasirinkimas) {
        case 1: {
            Palyginti();
            break;
        }
        default: cout << "Nera tokio pasirinkimo" << endl;
    }


    return 0;
}

void Palyginti() {
    cout << "Palyginti valiutos kursa su kita valiuta" << endl;
    cout << "Galimi valiutos kursu palyginimai" << endl;
    cout << "1. EUR su GBP" << endl;
    cout << "2. EUR su USD" << endl;
    cout << "3. EUR su INR" << endl;
    cout << "4. GBP su EUR" << endl;
    cout << "5. GBP su USD" << endl;
    cout << "6. GBP su INR" << endl;
    cout << "7. USD su EUR" << endl;
    cout << "8. USD su GBP" << endl;
    cout << "9. USD su INR" << endl;
    cout << "10. INR su EUR" << endl;
    cout << "11. INR su USD" << endl;
    cout << "12. INR su GBP" << endl;
    int kursas;
    cin >> kursas;
    double kiekis;
    switch (kursas) {
        case 1: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURtoGBP = kiekis * GBP_Bendras;
            cout << "EUR palygintas su GBP: " << fixed << setprecision(3) << EURtoGBP << endl;
            break;
        }
        case 2: {
            cout << "EUR kiekis: " << endl;
            cin >> kiekis;
            double EURtoUSD = kiekis * USD_Bendras;
            cout << "EUR palygintas su USD: " << fixed << setprecision(3) << EURtoUSD << endl;
            break;
        }
        default: cout << "Nera tokio pasirinkimo" << endl;
    }
}
