#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int notp[maxn];
int era(int n) {
    int cnt = 0;
    notp[0] = notp[1] = 1;
    for(int i = 2; i <= n / i; i++) {
        if(!notp[i]) {
            for(int j = i << 1; j <= n; j += i) {
                notp[j] = 1;
            }
            cnt++;
        }
    }
    return cnt;
}

vector<int> split(int n) {
    vector<int> v;
    for(int i = 2; i <= n / i; i++) {
        if(!notp[i] && n % i == 0) {
            v.push_back(i);
            for(; n % i == 0; n /= i);
        }
    }
    if(n > 1) v.push_back(n);
    return v;
}
int a[maxn], b[maxn], vis[maxn];
int n, ans;
vector<vector<int> > fac;
void dfs(int cur, int tot) {
    if(tot > ans) return;
    if(cur == n) {
        /*
        if(tot < ans) {
            for(int i = 0; i < n; i++) cout << b[i] << " ";
        }
        cout << endl;
        */
        ans = min(tot, ans);
        return;
    }
    for(int i = 0; i < fac[cur].size(); i++) {
        b[cur] = fac[cur][i];
        if(!vis[fac[cur][i]]) {
            vis[fac[cur][i]]++;
            dfs(cur + 1, tot + fac[cur][i]);
            vis[fac[cur][i]]--;
        }
    }
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    era(maxn - 1);
    for(int i = 1; i <= n; i++) {
        fac.push_back(split(a[i]));
    }
    ans = 0x7fffffff;
    dfs(0, 0);
    cout << ((ans == 0x7fffffff) ? -1 : ans) << endl;
    return 0;
}
