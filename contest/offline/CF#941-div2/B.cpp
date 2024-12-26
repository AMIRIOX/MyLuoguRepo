/* I don't know what it is
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int sq[maxn][maxn];
int n, m;
bool mok[maxn][maxn];

bool check(int lux, int luy, int xl, int yl) {
    if(sq[lux][luy] == sq[lux+xl][luy+yl]) return true;
    if(sq[lux+xl][luy] == sq[lux][luy+yl]) return true;
    if(xl <= 2 && yl <= 2) return false;
    else return 
        check(lux, luy, lux+xl-1, luy+yl) || check(lux, luy, lux+xl, luy+yl-1) || check(lux, luy, lux+xl-1, luy+yl-1) || 
        check(lux+1, luy, lux+xl, luy+yl) || check(lux, luy+1, lux+xl, luy+yl) || check(lux+1, luy+1, lux+xl, luy+yl);
}

void solve() {
    memset(sq, 0, sizeof(sq));
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) { 
            char tmp = 0; cin >> tmp;
            if(tmp == 'B') sq[i][j] = 1;
            else sq[i][j] = 0;
        }
    }

    if(check(0, 0, n, m)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int sq[maxn][maxn];
int n, m;

void solve() {
    memset(sq, 0, sizeof sq);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) { 
            char tmp = 0; cin >> tmp;
            if(tmp == 'B') sq[i][j] = 1;
            else sq[i][j] = 0;
        }
    }
 
    if(n == 1 && m == 1) {
        cout << "YES" << endl;
        return;
    }
    if(n == 1) {
        if(sq[0][0] == sq[0][m-1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }else if(m == 1) {
        if(sq[0][0] == sq[n-1][0]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }else {
   
        if(sq[0][0] == sq[n-1][m-1] ||
            sq[0][m-1] == sq[n-1][0]) {
            cout << "YES" << endl;
            return;
        }
    
        if(sq[0][0] != sq[0][m-1]) {
            for(int i = 1; i < n-1; i++) {
                if(sq[i][0] != sq[0][0] || sq[i][m-1] != sq[0][m-1]) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }else {
            for(int j = 1; j < m-1; j++) {
                if(sq[0][j] != sq[0][m-1] || sq[n-1][j] != sq[n-1][m-1]) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
