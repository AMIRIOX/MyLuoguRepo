#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn], b[maxn], n, *nowF;
// void printAns() {

// }
int* F(int arr[], int maxd) {
    int* tmp=new int[maxn], ind=0;
    for (int i = 1; i < maxd; i++) {
        tmp[ind++] = a[i] + a[i - 1];
    }
    sort(tmp, tmp + (maxd - 1));
    return tmp;
}
bool dfs(int cur) {
    if (cur == n) {
        // for (int i = 0; i < n; i++) printf("%d ", a[i]);
        // printf("\n");
        int* farr = F(a, n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (farr[i] != nowF[i]) ok = false;
        }
        delete[] farr;
        if (ok) {
            //printAns();
            for(int i=0;i<n;i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
            return true;
        } else
            return false;
    }
    for (int i = 1; i <= n; i++) {
        int ok = 1;
        for (int j = 0; j < cur; j++)
            if (i == a[j]) ok = 0;
        if (ok) {
            a[cur] = i;
            bool geted = dfs(cur + 1);
            if(geted) break;
        }
    }
    return true;
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> b[i];
        memset(nowF, 0, n);
        nowF = F(b, n);
        dfs(0);
    }
    return 0;
}