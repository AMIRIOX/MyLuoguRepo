#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin >> a;
    //cout << a[0] << a[1] << a[2];
    if (a[0] == 'M' && a[1] == 'D' && a[2] == 'A') {
        int ind;
        for (ind = (int)a.length(); a[ind] < '0' || a[ind] > '9'; ind--)
            ;
        int num = a[ind] - '0';
        //cout << a[ind];
        if (num == 1 || num == 9) {
            cout << "1 0 0 0 0";
        } else if (num == 2 || num == 8) {
            cout << "0 1 0 0 0";
        } else if (num == 3 || num == 7) {
            cout << "0 0 1 0 0";
        } else if (num == 4 || num == 6) {
            cout << "0 0 0 1 0";
        } else if (num == 5 || num == 0) {
            cout << "0 0 0 0 1";
        }
    } else if (a[0] != 'M' || a[1] != 'D' || a[2] != 'A'){
        //cout << "fuck";
        for (int i = 1; i <= 5; i++) {
            cout << 1 << " ";
        }
    }
    system("pause");
    return 0;
}