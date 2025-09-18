//1 užduotis
#include <iostream>
#include <string>
using namespace std;
int main()
{
    //Pirma uzd
    string Vardas = "Demianas", Pavarde = "Gulidovas", Grupe = "PI25", StudProgramPav = "Programu sistemos";
    int Amzius = 19, Kursas = 1;

    cout << "Pirma uzduotis" << endl;
    cout << "Vardas: " << Vardas << endl;
    cout << "Pavarde: " << Pavarde << endl;
    cout << "Amzius: " << Amzius << endl;
    cout << "Kursas: " << Kursas << endl;
    cout << "Grupe: " << Grupe << endl;
    cout << "Studiju programos pavadinimas: " << StudProgramPav << endl;
    cout << endl;

    //Antra uzd
    string Pavadinimas = "Kauno Zalgiris", Arena = "Zalgirio Arena", Savininkas ="Paulius Jankukas";
    int IkurMet = 1944, VietSk = 15415;
    cout << "Antra uzduotis" << endl;
    cout << "Pavadinimas: " << Pavadinimas << endl;
    cout << "Arena: " << Arena << endl;
    cout << "Vietu Skaicius: " << VietSk << endl;
    cout << "Savininkas: " << Savininkas << endl;
    cout << "Ikurimo metai: " << IkurMet << endl;
    cout << endl;

    //Trečia užduotis
    string marke = "Mazda", modelis = "3", spalva = "Raudo";
    int metai = 2019;
    double litrazas = 2.0;
    cout << "Trecia uzduotis" << endl;
    cout << "Marke: " << marke << endl;
    cout << "Modelis: " << modelis << endl;
    cout << "Spalva: " << spalva << endl;
    cout << "Metai: " << metai << endl;
    cout << "Litrazas: " << litrazas << endl;
    cout << endl;
    //Ketvirta užduotis
    int a = 13, b = 5;
    double c = 17.5;
    cout << "Ketvirta uzduotis" << endl;
    cout << a + b - c << endl;
    cout << 15/2 + 17.5 << endl;
    cout << a/ static_cast<double>(b) + 2*c << endl;
    cout << 14 % 3 + 6.3 + b/a << endl;
    cout << static_cast<int>(c)%5+a-b << endl;
    cout << 13.5/2+4.0*3.5+18 << endl;
    cout << endl;
    //Penkta užduotis
    double A5,B5,C5,D5,E5;
    cin >> A5 >> B5 >> C5 >> D5 >> E5;
    double ATS = (A5+B5+C5+D5+E5)/5;
    cout <<"Vidurkis: " << ATS << endl;
    return 0;
}
