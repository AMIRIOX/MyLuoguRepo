#include <iostream>
using namespace std;
int f[1000020],h[1000020];
#define MOD 10000
int main() {
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = h[1] = 1;
    for(int i=2; i<=n; ++i) {
        f[i] = ((f[i-1] + f[i-2])%MOD + (h[i-2]*2)%MOD)%MOD;
        h[i] = (f[i-1] + h[i-1])%MOD;
    }
    cout << f[n];
    return 0;
}
