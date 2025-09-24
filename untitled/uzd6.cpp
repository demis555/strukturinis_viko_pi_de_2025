#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double pradineSuma = 1000.0;
    double palukanuNorma = 0.05; // 5%
    int metai = 10;

    double galutineSuma = pradineSuma * pow(1 + palukanuNorma, metai);

    cout << "Po " << metai << " metu klientas gaus: " << galutineSuma << " EUR" << endl;

    return 0;
}