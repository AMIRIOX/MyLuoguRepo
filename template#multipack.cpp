#include <iostream>
using namespace std;
const int maxn = 1e5+10;
int dp[maxn], n, W, c[maxn], w[maxn];
int main() {
    cin >> n >> W;
    int ind = 0;
    for(int i = 1;i <= n;i++) {
        int value, weight, mi;
        cin >> value >> weight >> mi;
        int C = 1;
        while(mi > C) {
            mi -= C;
            c[++ind] = C * weight;
            w[ind] = C * value;
            C *= 2;
        }
        if(mi) {
            c[++ind] = mi * weight;
            w[ind] = mi * value;
        }
    }
    for(int i = 1; i <= ind; i++) {
        for(int j = W; j >= 0; j--) {
            if(j >= c[i]) dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }
    cout << dp[W] << endl;
}
