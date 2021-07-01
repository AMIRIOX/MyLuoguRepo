#include <cstdio>
#include <iostream>
#define maxn 1000000
using namespace std;
int F[maxn], G[maxn];
signed main() {
    int n;
    scanf("%d", &n);
    // F[N]=F[N-1]+F[N-2]+2*G[N-1]
    // G[N]=F[N-2]+G[N-1]
    F[1] = 1;
    F[2] = 2;
    G[2] = 1;
    for (int i = 3; i <= n; i++) {
        F[i] = ((F[i - 1] + F[i - 2])%10000 + 2 * G[i - 1]%10000)%10000;
        G[i] = (F[i - 2] + G[i - 1])%10000;
    }
    cout << F[n]%10000 << endl;
    return 0;
}