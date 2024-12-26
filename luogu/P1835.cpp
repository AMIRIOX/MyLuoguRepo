#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 1e4;
int prime[maxn], a[maxn], ans;
int eraSieve(int n, int pri[]) {
    for (int i = 2; i * i <= n; i++) {
        if (a[i] == 0) {
            for (int j = i << 1; j <= n; j += i) {
                a[j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!a[i]) pri[cnt++] = i;
    }
    return cnt;
}
int main() {
    int total = eraSieve(50000, prime);
    long long L, R;
    cin >> L >> R;
    memset(a, 0, sizeof a);
    for (int i = 0; i < total; i++) {
        for (long long j = max(2ll, (L - 1) / prime[i] + 1) * prime[i]; j <= R;
             j += prime[i]) {
            a[j - L] = 1;
        }
    }
    for (long long i = L; i <= R; i++)
        if (!a[i - L]) ans++;
    cout << ans;
    return 0;
}