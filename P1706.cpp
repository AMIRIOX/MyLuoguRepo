#include <bits/stdc++.h>
using namespace std;
int n, ans[11], vis[10];
void dfs(int level) {
    if (level == n) {
        cout.setf(ios::fixed);
        for (int i = 0; i < n; i++) {
            cout <<setw(5)<<setfill(' ')<< ans[i] ;
        }
        cout << endl;
        return;
    } else {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                ans[level] = i;
                dfs(level + 1);
                vis[i] = 0;
            }
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    system("pause");
    return 0;
}