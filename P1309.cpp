#include <algorithm>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
struct dy {
    int ind, score, abi;
    dy() {}
    dy(const dy& o) {
        ind = o.ind;
        score = o.score;
        abi = o.abi;
    }
} a[maxn], win[maxn], lose[maxn];
bool cmp(const dy& a, const dy& b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.ind < b.ind;
}
void merge() {
    int i = 1, j = 1;
    int cnt = 0;
    while (i <= win[0].ind && j <= lose[0].ind) {
        if (cmp(win[i], lose[j])) {
            a[++cnt] = win[i++];
        } else {
            a[++cnt] = lose[j++];
        }
    }
    while (i <= win[0].ind) a[++cnt] = win[i++];
    while (j <= lose[0].ind) a[++cnt] = lose[j++];
}
signed main() {
    int N, R, Q;
    cin >> N >> R >> Q;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> a[i].score;
        a[i].ind = i;
    }
    for (int i = 1; i <= 2 * N; i++) cin >> a[i].abi;
    sort(a + 1, a + (N * 2) + 1, cmp);
    for (int i = 1; i <= R; i++) {
        win[0].ind = 0;
        lose[0].ind = 0;
        for (int j = 1; j <= 2 * N; j += 2) {
            if (a[j].abi > a[j + 1].abi) {
                a[j].score++;
                win[++(win[0].ind)] = a[j];
                lose[++(lose[0].ind)] = a[j + 1];
            } else {
                a[j + 1].score++;
                win[++(win[0].ind)] = a[j + 1];
                lose[++(lose[0].ind)] = a[j];
            }
        }
        merge();
    }
    cout << a[Q].ind << endl;
    return 0;
}