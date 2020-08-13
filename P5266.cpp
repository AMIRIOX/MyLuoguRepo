#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<string, int> ds;
int n, opt, SCORE, ans;
string NAME;
int main() {
    cin >> n;
    while (n--) {
        cin >> opt;
        if (opt == 1) {
            cin >> NAME >> SCORE;
            if (!ds[NAME]) ans++;
            ds[NAME] = SCORE;
            cout << "OK" << endl;
        } else if (opt == 2) {
            cin >> NAME;
            if (ds[NAME]) {
                cout << ds[NAME] << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else if (opt == 3) {
            cin >> NAME;
            if (ds[NAME])
                ds[NAME] = 0, cout << "Deleted successfully" << endl, ans--;
            else
                cout << "Not found" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}