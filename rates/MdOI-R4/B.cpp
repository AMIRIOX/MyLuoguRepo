#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T;
const int maxn = 1e5 + 10;
int p[2][maxn];
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(p, 0, sizeof(p));
        int n = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%1d", &p[0][i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%1d", &p[1][i]);
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) {
            // process [0]
            if (p[0][i] == 1) {
                bool oksa = false;
                if (!oksa && i > 1 && p[0][i - 1] != 2 && p[0][i - 1] != 1)
                    oksa = true, p[0][i - 1] = 2;
                if (!oksa && p[1][i] != 2 && p[1][i] != 1)
                    oksa = true, p[1][i] = 2;
                if (!oksa && i < n && p[0][i + 1] != 2 && p[0][i + 1] != 1)
                    oksa = true, p[0][i + 1] = 2;
                if (!oksa) {
                    ok = false;
                    // cout << 0 << " " << i << " has problem." << endl;
                    // for (int i = 1; i <= n; i++)
                    //     cout << p[0][i];
                    // cout << endl;
                    // for (int i = 1; i <= n; i++)
                    //     cout << p[1][i];
                    break;
                }
            }
            // process [1]
            if (p[1][i] == 1) {
                bool oksb = false;
                if (!oksb && i > 1 && p[1][i - 1] != 2 && p[1][i - 1] != 1)
                    oksb = true, p[1][i - 1] = 2;
                if (!oksb && p[0][i] != 2 && p[0][i] != 1)
                    oksb = true, p[0][i] = 2;
                if (!oksb && i < n && p[1][i + 1] != 2 && p[1][i + 1] != 1)
                    oksb = true, p[1][i + 1] = 2;
                if (!oksb) {
                    ok = false;
                    // cout << 1 << " " << i << " has problem." << endl;
                    break;
                }
            }
        }
        if (ok)
            printf("RP\n");
        else
            printf("++\n");
    }
    return 0;
}