#include <cstdio>
#include <iostream>
#define INF 0x7fffffff
// #define int long long
using namespace std;
const int MAXN = 1e6 + 1;
int zw[MAXN], cnt = 1;
int n, k;
int calcSingleD(int i) {
    int cursor = i, maxc = 0, maxs = 0;
    while (!zw[cursor] || cursor == i) {
        if (cursor != i && zw[cursor] == 0) maxc++;
        if (cursor == 1)
            cursor = n;
        else
            cursor--;
    }
    maxs += maxc;
    cursor = i, maxc = 0;
    while (!zw[cursor] || cursor == i) {
        if (cursor != i && zw[cursor] == 0) maxc++;
        if (cursor == n)
            cursor = 1;
        else
            cursor++;
    }
    maxs = min(maxc, maxs);
    return maxs;
}
int calcMaxd() {
    int maxnd = -INF;
    for (int i = 1; i <= n; i++) {
        maxnd = max(maxnd, calcSingleD(i));
    }
    return maxnd;
}
int main() {
    cin >> n >> k;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    zw[1] = 1;
    while (1) {
        if (cnt == 1) {
            zw[(1 + n - 1) / 2] = 1;
            cnt++;
            continue;
        }
        int maxv = -INF;
        for (int i = 1; i <= n; i++) {
            if (zw[i] == 0) {
                zw[i]=1;
                int maxt = calcMaxd();
                cout << "maxt: " << maxt<< endl;
                if(maxt==1)cout << "maxiiii: " << i << endl;
                maxv=max(maxv,maxt);
                zw[i]=0;
            }
        }
        cout << maxv << endl;
        if (maxv < k) break;
        zw[maxv] = 1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}