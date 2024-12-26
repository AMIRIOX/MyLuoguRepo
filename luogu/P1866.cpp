#include <algorithm>
#include <iostream>
#define mod 1000000007
using namespace std;
long long ans = 1ll, num[10010];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    for (int i = 0; i < n; i++) {
        ans *= (num[i] - i);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}