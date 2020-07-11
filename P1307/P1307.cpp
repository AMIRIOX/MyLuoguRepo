#include <iostream>
#include <string>
using namespace std;
void dFz(string& a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '0' && a[i] != '-') break;
        a[i] = '-';
    }
}
void dLz(string& a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != '0' || a[i]=='-') break;
        a[i] = '-';
    }
}
int main() {
    string num;
    cin >> num;

    if (num[0] == '-') cout << "-";
    dFz(num); dLz(num);
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] == '-') continue;
        else cout << num[i];
    }
    return 0;
}