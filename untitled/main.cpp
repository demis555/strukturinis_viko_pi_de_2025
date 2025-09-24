#include <iostream>
using namespace std;
int main()
{
    //pirma ir antra uzduotis
    int a,b,c,d,e;
    cout << "ivesti penkis skaicius:" << endl;
    cin >> a >> b >> c >> d >> e;
    int sum = a + b + c + d + e;
    double vid=static_cast<double>(sum)/5;
    if(vid>=5) {
        cout << "Vidurkis teigiamas" << endl;
    } else {
        cout << "Vidurkis neigiamas" << endl;
    }

    return 0;
}
