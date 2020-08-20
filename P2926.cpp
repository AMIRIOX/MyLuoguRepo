#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 10;
int ans[MAXN], origin[MAXN], nums[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> origin[i], nums[origin[i]]++;
    }
    // cout << "input ok" << endl;
    for (int i = 1; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j += i) {
            ans[j] += nums[i];
        }
    }
    // cout << "get answer ok" << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[origin[i]] - 1 << endl;
    }
    return 0;
}