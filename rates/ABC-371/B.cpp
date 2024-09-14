#include <bits/stdc++.h>
using namespace std;
bool tarod[200];
signed main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int Ai; char Bi;
        cin >> Ai >> Bi;
        if(!tarod[Ai] && Bi == 'M') {
            cout << "Yes" << endl;
            tarod[Ai] = 1;
        }else cout << "No" << endl;
    }
    return 0;
}
