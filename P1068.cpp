#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
struct st {
    int ind;
    int val;
    bool operator<(const st& b) const {
        if (val == b.val) return ind < b.ind;
        return val > b.val;
    }
    bool operator>(const st& b) const {
        if (val == b.val) return ind > b.ind;
        return val < b.val;
    }
} a[10001];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].ind, &a[i].val);
    }
    sort(a, a + n);
    int tot = 0;
    int o = int((double(m) * 1.5));
    int score = a[o - 1].val;
    for (int i = 0; i < n; i++) {
        if (a[i].val >= score) {
            tot++;
        } else {
            break;
        }
    }
    printf("%d %d\n", score, tot);
    for (int i = 0; i < n; i++) {
        if (a[i].val >= score) {
            printf("%d %d\n", a[i].ind, a[i].val);
        } else {
            break;
        }
    }
    system("pause");
    return 0;
}