#include <iostream>
#define now xs[i]
using namespace std;
int xs[120];
int main(/*int argc, char const *argv[]*/) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> now;
    }
    int cf = n;
    for (int i = 0; i <= n; i++) {
        if (now == 0) {
            cf--;
            continue;
        } else if (now > 0 && i != 0) {
            cout << "+";
        } else if (now < 0)
            cout << '-';
        if (now != 1 && now != -1) cout << ((now > 0) ? now : -now);
        if (cf == 0 && (now == 1 || now == -1)) cout << "1";
        if (cf == 1)
            cout << "x";
        else if (cf != 0)
            cout << "x^" << cf;
        cf--;
    }
    // cout << endl << cf;
    system("pause");
    return 0;
}
