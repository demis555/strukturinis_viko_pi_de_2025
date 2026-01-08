#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

struct Studentas {
    string id;
    string atsakymai;
    int taskai;
    double procentai;
    int pazymys;
};

// Funkcijų prototipai
void skaitytiDuomenis(vector<Studentas>& studentai, string& teisingiAtsakymai);
void issaugotiRezultatus(const vector<Studentas>& studentai);
void klasesStatistika(const vector<Studentas>& studentai);
void klausimuStatistika(const vector<Studentas>& studentai, const string& teisingiAtsakymai);
void sunkiausiasKlausimas(const vector<Studentas>& studentai, const string& teisingiAtsakymai);
void ieskotiStudento(const vector<Studentas>& studentai);

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    vector<Studentas> studentai;
    string teisingiAtsakymai;

    skaitytiDuomenis(studentai, teisingiAtsakymai);

    if (studentai.empty()) {
        cout << "Duomenų faile nėra studentų arba failas neteisingas." << endl;
        return 1;
    }

    issaugotiRezultatus(studentai);

    klasesStatistika(studentai);
    klausimuStatistika(studentai, teisingiAtsakymai);
    sunkiausiasKlausimas(studentai, teisingiAtsakymai);
    ieskotiStudento(studentai);

    return 0;
}
//nuskaito duomenis
void skaitytiDuomenis(vector<Studentas>& studentai, string& teisingiAtsakymai) {
    ifstream fin("testdata.txt");

    getline(fin, teisingiAtsakymai);

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        size_t spacePos = line.find(' ');
        if (spacePos == string::npos) continue;

        string id = line.substr(0, spacePos);
        string ats = line.substr(spacePos + 1);

        if (ats.length() != 20) continue;

        Studentas s;
        s.id = id;
        s.atsakymai = ats;

        int score = 0;
        for (int i = 0; i < 20; i++) {
            char studentAns = ats[i];
            char correctAns = teisingiAtsakymai[i];

            if (studentAns == 'T' || studentAns == 'F') {
                if (studentAns == correctAns) {
                    score += 2;
                } else {
                    score -= 1;
                }
            }
        }

        s.taskai = score;
        s.procentai = (score / 40.0) * 100.0;

        if (s.procentai >= 95.0) s.pazymys = 10;
        else if (s.procentai >= 85.0) s.pazymys = 9;
        else if (s.procentai >= 75.0) s.pazymys = 8;
        else if (s.procentai >= 65.0) s.pazymys = 7;
        else if (s.procentai >= 55.0) s.pazymys = 6;
        else if (s.procentai >= 50.0) s.pazymys = 5;
        else if (s.procentai >= 35.0) s.pazymys = 4;
        else if (s.procentai >= 25.0) s.pazymys = 3;
        else if (s.procentai >= 15.0) s.pazymys = 2;
        else s.pazymys = 1;

        studentai.push_back(s);
    }
    fin.close();
}

void issaugotiRezultatus(const vector<Studentas>& studentai) {
    ofstream fout("results.txt");

    fout << fixed << setprecision(2);
    for (int i = 0; i < studentai.size(); i++) {
        fout << studentai[i].id << " " << studentai[i].taskai << " "
             << studentai[i].procentai << "% " << studentai[i].pazymys << endl;
    }
    fout.close();
    cout << "Rezultatai išsaugoti faile." << endl;
}

void klasesStatistika(const vector<Studentas>& studentai) {
    int n = studentai.size();

    int pazymiuKiekis[11] = {0};
    double sumProcentai = 0.0;
    double sumPazymiai = 0.0;
    int maxPaz = 0, minPaz = 11;

    for (int i = 0; i < n; i++) {
        pazymiuKiekis[studentai[i].pazymys]++;
        sumProcentai += studentai[i].procentai;
        sumPazymiai += studentai[i].pazymys;
        if (studentai[i].pazymys > maxPaz) maxPaz = studentai[i].pazymys;
        if (studentai[i].pazymys < minPaz) minPaz = studentai[i].pazymys;
    }

    cout << "=== Klasės statistika ===" << endl;
    cout << "Studentų skaičius: " << n << endl;
    cout << "Didžiausias pažymys: " << maxPaz << endl;
    cout << "Mažiausias pažymys: " << minPaz << endl;
    cout << fixed << setprecision(2);
    cout << "Vidutinis pažymys: " << (sumPazymiai / n) << endl;
    cout << "Vidutinis procentas: " << (sumProcentai / n) << "%" << endl;

    cout << "Pažymių pasiskirstymas:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << " balų: " << pazymiuKiekis[i] << " studentai" << endl;
    }
}
//kiekvieno klausimo statistika
void klausimuStatistika(const vector<Studentas>& studentai, const string& teisingiAtsakymai) {
    int n = studentai.size();

    int teisingai[20] = {0};
    int neteisingai[20] = {0};
    int neatsake[20] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            char ans = studentai[i].atsakymai[j];
            char cor = teisingiAtsakymai[j];

            if (ans == 'T' || ans == 'F') {
                if (ans == cor) teisingai[j]++;
                else neteisingai[j]++;
            } else {
                neatsake[j]++;
            }
        }
    }

    cout << "\n=== Klausimų statistika ===" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "Klausimas " << (i + 1) << ": teisingai – " << teisingai[i]
             << ", neteisingai – " << neteisingai[i]
             << ", neatsakė – " << neatsake[i] << endl;
    }
}
// sunkaisio klausimo nustatymas
void sunkiausiasKlausimas(const vector<Studentas>& studentai, const string& teisingiAtsakymai) {
    int n = studentai.size();

    int teisingai[20] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            char ans = studentai[i].atsakymai[j];
            if (ans == teisingiAtsakymai[j] && (ans == 'T' || ans == 'F')) {
                teisingai[j]++;
            }
        }
    }

    double minProcentas = 101.0;
    vector<int> sunkiausi;

    for (int i = 0; i < 20; i++) {
        double proc = (teisingai[i] * 100.0) / n;
        if (proc < minProcentas - 0.01) {
            minProcentas = proc;
            sunkiausi.clear();
            sunkiausi.push_back(i + 1);
        } else if (abs(proc - minProcentas) < 0.01) {
            sunkiausi.push_back(i + 1);
        }
    }

    cout << "\n=== Sunkiausias(-i) klausimas(-ai) ===" << endl;
    cout << "Klausimas(-ai): ";
    for (int i = 0; i < sunkiausi.size(); i++) {
        if (i > 0) cout << ", ";
        cout << sunkiausi[i];
    }
    cout << " (teisingų atsakymų procentas: " << fixed << setprecision(2) << minProcentas << "%)" << endl;
}
// studento paieška
void ieskotiStudento(const vector<Studentas>& studentai) {
    cout << "\n=== Studento paieška pagal ID ===" << endl;
    while (true) {
        string id;
        cout << "Įveskite studento ID (0 – išeiti): ";
        cin >> id;

        if (id == "0") break;

        bool rastas = false;
        for (int i = 0; i < studentai.size(); i++) {
            if (studentai[i].id == id) {
                cout << fixed << setprecision(2);
                cout << "Studentas " << studentai[i].id << ": " << studentai[i].taskai << " taškai, "
                     << studentai[i].procentai << "% , pažymys " << studentai[i].pazymys << endl;
                rastas = true;
                break;
            }
        }
        if (!rastas) {
            cout << "Studentas su ID \"" << id << "\" nerastas." << endl;
        }
    }
}