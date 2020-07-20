#include <algorithm>
#include <iostream>
using namespace std;
int x, n, ans, a[1000005];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> x >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        if (a[i] == x + 1) continue;
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] <= x && a[j] != x + 1) {
                //cout << ans + 1 << " " << a[i] << " " << a[j] << endl;
                a[j] = x + 1;
                ans++;
                break;
            }
            if (j == n - 1) {
                ans++;
                //cout << ans << " " << a[i] << endl;
            }
        }
    }
    cout << ans;
    return 0;
}