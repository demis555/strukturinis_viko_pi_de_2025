#include <iostream>
#include <fstream>

using namespace std;

const int Nmax = 10;

const char Menu[]="menu.txt";

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menu[], int& n);
void showMenu();
void printCheck();

int main() {
    int pasirink;
    int n = 0;
    menuItemType menu[Nmax];
    showMenu();
    getData(menu, n);


    return 0;
}
void showMenu() {

}

void getData(menuItemType menu[], int& n) {

    ifstream menuFile(Menu);

    int i = 0;
    while (i < Nmax && (menuFile >> menu[i].menuItem >> menu[i].menuPrice)) {
        cout << menu[i].menuItem << " " << menu[i].menuPrice << endl;
        i++;
    }
    n = i;
}

void printCheck() {

}

