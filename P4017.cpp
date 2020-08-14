#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
const int mod = 80112002;
const int maxn = 100010;
int ind[maxn], outd[maxn], f[maxn], ans;
vector<int> gr[maxn];
queue<int> q;
using namespace std;
int main() {
    int n, m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        outd[x]++;
        ind[y]++;
        gr[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            f[i] = 1;
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0, sz = gr[x].size(); i < sz; i++) {
            int y = gr[x][i];
            f[y] = (f[x] + f[y]) % mod;
            ind[y]--;
            if (ind[y] == 0) q.push(y);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (outd[i] == 0) ans = (ans + f[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}