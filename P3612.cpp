#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
string x;
int n;
signed main() {
    cin >> x >> n;
    int maxnn = n / (x.length()) + 1;
    for (size_t i = 1; i < maxnn; i++) {
        string t = x;
        t.insert(t.begin(), x[x.length() - 1]);
        t = t.substr(0, t.length() - 1);
        x += t;
    }
    // cout << x << endl;
    cout << x[n - 1];
    return 0;
}