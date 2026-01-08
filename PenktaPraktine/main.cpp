#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

const int MAX = 20;

struct Student {
    string ID;
    int Points[MAX];
};

void GetData();
void ShowMenu();
void ShowResult();

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    vector<Student> TestAts;
    GetData();
    ShowMenu();

    return 0;
}

void ShowMenu(){
    cout << "========Testo rezultatai========" << endl;
}