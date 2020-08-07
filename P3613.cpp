#include <iostream>
#include <vector>
using namespace std;
int cmd, i, j, k;
int main() {
    int n, q;
    cin >> n >> q;
    vector< vector<int> > jbg(n + 1);
    while (q--) {
        /* code */
        cin >> cmd;
        if (cmd == 1) {
            cin >> i >> j >> k;
            if (j>=jbg[i].size()) {
                jbg[i].resize(j+1);
            }
            jbg[i][j]=k;
        }else {
            cin >> i >> j;
            cout << jbg[i][j] << endl;
        }
    }
    return 0;
}