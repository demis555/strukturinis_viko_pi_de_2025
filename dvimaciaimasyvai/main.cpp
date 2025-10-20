#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int students = 8;
    const int subjects = 4;

    string subjectNames[subjects] = {"Istorija", "Matematika", "Informatika", "Anglų"};
    int pazymiai[students][subjects] = {}; // inicializuojame 0

    // Įvedimas
    for (int i = 0; i < students; ++i) {
        cout << "---- Studentas " << i+1 << " ----\n";
        for (int j = 0; j < subjects; ++j) {
            cout << "Įveskite " << i+1 << " studento pažymį dalykui: " << subjectNames[j] << " : ";
            cin >> pazymiai[i][j];
        }
        cout << '\n';
    }

    // Išvedimas lentelėje
    const int nameWidth = 12;
    const int colWidth = 10;

    cout << left << setw(nameWidth) << "Studentas";
    for (int j = 0; j < subjects; ++j) cout << setw(colWidth) << subjectNames[j];
    cout << setw(colWidth) << "Vidurkis" << '\n';

    cout << string(nameWidth + colWidth * (subjects + 1), '-') << '\n';

    for (int i = 0; i < students; ++i) {
        string label = "Nr." + to_string(i+1);
        cout << left << setw(nameWidth) << label;
        int sum = 0;
        for (int j = 0; j < subjects; ++j) {
            cout << setw(colWidth) << pazymiai[i][j];
            sum += pazymiai[i][j];
        }
        double avg = static_cast<double>(sum) / subjects;
        cout << fixed << setprecision(2) << setw(colWidth) << avg << '\n';
    }

    return 0;
}