#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
long long dp[10][500];
signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;

    for(int i = 0; i < s.length(); i++) {
        dp[3][s[i]] += dp[2][s[i]];
        for(char c = 'a'; c <= 'z'; c++)
            if(s[i] != c) dp[2][s[i]] += dp[1][c];
        dp[1][s[i]]++;
    }

    for(char c = 'a'; c <= 'z'; c++) ans += dp[3][c];
    cout << ans << endl;
    return 0;   
}
