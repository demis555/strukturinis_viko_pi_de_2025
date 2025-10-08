#include <iostream>
#include <random>
#include <string>
using namespace std;
int main() {

    int arr[40];
    int count[11] = {0}; 
    string countedArrayText[10];
    int countedArrayNums[10];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < 40; i++) {
        arr[i] = dis(gen);
        count[arr[i]]++;
    }

    cout << "Studentu ivertinimai:" << endl;
    for (int i = 0; i < 40; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;

    cout << "Ivertinimu pasikartojimas:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "Ivertinimas " << i << " pasikartojo " << count[i] << " kartus" << endl;
        countedArrayNums[i-1] = count[i];
        countedArrayText[i-1] = "Ivertinimas " + to_string(i) + " pasikartojo " + to_string(count[i]) + " kartus";
    }

     cout << "\nPasikartojimo masyvas su aprasymu:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Skaicius: " << countedArrayNums[i] << " | Aprasymas: " << countedArrayText[i] << endl;
    }

    return 0;
}
