#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#define re register
using namespace std;
const int maxn = 100010;
queue<int> q;
set<int> mem;
int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (!q.empty() && !mem.empty() && mem.find(t) != mem.end()) {
            continue;
        } else {
            ans++;
            if (q.size() >= m) {
                int va = q.front();
                q.pop();
                if (set<int>::iterator iv = mem.find(va); iv != mem.end())
                    mem.erase(iv);
                q.push(t);
                mem.insert(t);
            }else {
                q.push(t);
                mem.insert(t);
            }
        }
    }
    cout << ans;
    return 0;
}