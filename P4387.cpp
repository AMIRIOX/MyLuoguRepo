#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
// #define int long long
using namespace std;
const int maxn = 1e5 + 10;
vector<int> pushed;
vector<int> poped;
stack<int> s;
signed main() {
    int q, n, c;
    cin >> q;
    while (q--) {
        pushed.clear();
        poped.clear();
        stack<int>().swap(s);
        cin >> n;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cin >> c;
            pushed.push_back(c);
        }
        for (int i = 0; i < n; i++) {
            cin >> c;
            poped.push_back(c);
        }
        for (int i = 0; i < n; i++) {
            s.push(pushed[i]);
            if (cur >= n) break;
            while (!s.empty() && s.top() == poped[cur]) {
                s.pop();
                cur++;
            }
        }
        if (s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}