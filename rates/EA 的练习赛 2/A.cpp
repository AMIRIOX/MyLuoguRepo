#include <algorithm>
#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e8 + 10;

int d[maxn], a[maxn], n, w;
int ans = -INF;
signed main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = INF;
    }

    d[1] = a[1];
    int len = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= d[len])
            d[++len] = a[i];
        else
        {
            int in = upper_bound(d + 1, d + n + 1, a[i]) - d;
            d[in] = a[i];
        }
    }
    printf("%d", n == 1 ? 0 : n - len);
    // cout << n-1 << endl;
    return 0;
}