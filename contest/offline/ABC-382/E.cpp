#include <bits/stdc++.h>
#include <ios>
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    // 期望可能和 dp 相关
    vector<double> f(x + 1, 0);
    vector<double> g(n + 1, 0);

    // 注释掉的代码是可以 AC 的, 不过学一下这种比较灵动的 dp 写法
    //vector<vector<double>> g(n + 1, vector<double>(n + 1, 0));
    /*
    g[0][0] = 1;
    g[1][0] = 1 - p[1] / 100.0;
    for (int i = 2; i <= n; i++)
        g[i][0] = g[i - 1][0] * (1 - p[i] / 100.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = g[i - 1][j - 1] * (p[i] / 100.0) + g[i - 1][j] * (1 - p[i] / 100.0);
        }
    }
    */
    g[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            double q = p[i + 1] / 100.0;
            /*
            // 发现第一维都是 i 转移到i + 1, 可以压缩
            g[i + 1][j] += g[i][j] * (1 - p[i] / 100.0);
            g[i + 1][j + 1] += g[i][j] * (p[i] / 100.0);
            */
            // 注意一下这里后修改 g[j]
            g[j + 1] += g[j] * q;
            g[j] *= (1 - q);
        }
    }
    for (int i = 1; i <= x; i++) {
        double rt = 0;
        for (int j = 1; j <= n; j++) {
            rt += f[max(i - j, 0)] * g[j];
        }
        // f[i] = (rt + 1) / (1 - g[n][0]);
        f[i] = (rt + 1) / (1 - g[0]);
    }
    cout << fixed << setprecision(17) << f[x] << '\n';
    return 0;
}
