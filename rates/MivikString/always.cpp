#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;
string origin, strs[maxn], p;
vector<string> substrs;
int n;
signed main() {
    cin >> origin;
    for (int i = 0; i < origin.length(); i++) {
        for (int j = 0; j < origin.length(); i++) {
            if (i == j || j<i) continue;
            p = origin.substr(i, j - 1);
            if (find(substrs.begin(), substrs.end(), p) != substrs.end())
                substrs.push_back(p);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> strs[i];
    }
    for (int i = 1; i <= n; i++) {
        // strs[i];
        int ans = 0;
        for (int j = 0; j < substrs.size(); j++) {

            //substr[j];
            bool ok = true;
            if(strs[i].length()!=substrs[j].length()) continue;
            for (int k = substrs[j].length() - 1; k >= 0; k--) {
                if(substrs[j][k]!=strs[i][k]) ok=false;
                break;
            }
            if(ok) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}