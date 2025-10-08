#include <iostream>
using namespace std;
int main() {
    const int n = 5;
    int arr[n];
    cout << "Ivesti 5 skaicius i masyva:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minSk=arr[0];
    int maxSk=arr[0];
    int sum=0;

    for (int i = 0; i < n; i++) {
        sum=sum+arr[i];
        if(arr[i] < minSk)minSk=arr[i];
        if(arr[i] > maxSk)maxSk=arr[i];
    }
    cout << "Sum: " << sum << endl;
    cout << "Min: " << minSk << endl;
    cout << "Max: " << maxSk << endl;

    return 0;
}
