#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int pw = 86400;
const int maxn=3e5+10;
struct po {
    int time, nation;
} pos[maxn];
int n, cnt, nations[maxn], ntscnt;
queue<po> q;
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int ti, ki;
        scanf("%d %d", &ti, &ki);
        for (int j = 1; j <= ki; j++) {
            int xi;
            scanf("%d", &xi);
            pos[++cnt].time = ti;
            pos[cnt].nation = xi;
            q.push(pos[cnt]);
            if (!nations[xi])
                ntscnt++;
            nations[xi]++;
        }
        while (!q.empty() && ti - q.front().time >= pw) {
            nations[q.front().nation]--;
            if (!nations[q.front().nation])
                ntscnt--;
            q.pop();
        }
        printf("%d\n", ntscnt);
    }
    return 0;
}