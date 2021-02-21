#ifdef BRUTE_METHOD

#include <cstdio>
#include <iostream>
using namespace std;
int t;
signed main() {
    scanf("%d", &t);
    while (t--) {
        int a, b;
        int ans = 0x7fffffff;
        scanf("%d %d", &a, &b);
        for (int i = (b == 1); i <= 32; i++) {
            int oa = a;
            int ob = b + i;
            int cnt = 0;
            for (; oa; oa /= ob)
                cnt++;
            ans = min(ans, cnt + i);
        }
        printf("%d\n", ans);
    }
    return 0;
}

#endif

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct xi {
    int a, b, tms;
    xi(int _a, int _b, int _tms = 0) : a(_a), b(_b), tms(_tms){};
};
int a, b, t;  //, ans = 0x7fffffff;
void bfs() {
    queue<xi> q;
    q.push(xi(a, b));
    while (!q.empty()) {
        xi now = q.front();
        q.pop();

        if (now.a == 0) {
            printf("%d\n", now.tms);
            return;
            // ans = min(ans, now.tms);
        }
        // a/=b
        xi neg(now.a / now.b, now.b, now.tms + 1);
        q.push(neg);

        // b++
        xi add(now.a, now.b + 1, now.tms + 1);
        q.push(add);
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        // ans = 0x7fffffff;
        bfs();
        // printf("%d\n", ans);
    }
    return 0;
}