#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
vector<int> v;
signed main() {
    int T, n, c;
    cin >> T;
    while (T--) {
        v.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c;
            v.push_back(c);
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}