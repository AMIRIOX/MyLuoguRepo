#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int N, R, Q;
inline int read() {
    register int flag = 0, abs = 0;
    char x = getchar();
    while (x < '0' || x > '9') {
        if (x == '-') flag = 1;
        x = getchar();
    }
    while (x >= '0' && x <= '9') {
        abs = (abs << 3) + (abs << 1) + (x ^ 48);
        x = getchar();
    }
    return flag ? ~(abs - 1) : abs;
}
struct dy {
    int score;
    int abi;
    int index;
    dy() { score = 0, abi = 0, index = 0; }
    dy(const dy& d) {
        this->score = d.score;
        this->abi = d.abi;
        this->index = d.index;
    }
    dy& operator=(const dy& o) {
        this->abi = o.abi;
        this->score = o.score;
        this->index = o.index;
        return *this;
    }
    bool operator>(dy& x) {
        if(score!=x.score) return score>x.score;
        else return index<x.index;
    }
} a[maxn], temp[maxn];
inline void merge(int L, int mid, int R) {
    register int i = L, j = mid + 1, cnt = 1;
    while (i <= mid && j <= R) {
        if (a[i]>a[j]) {
            temp[cnt++] = a[i++];
        }
        if (a[j]>a[i]) {
            temp[cnt++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[cnt++] = a[i++];
    }
    while (j <= R) {
        temp[cnt++] = a[j++];
    }
    cnt = 1;
    while (L <= R) {
        a[L++] = temp[cnt++];
    }
}
inline void mergeSort(int L, int R) {
    if (L < R) {
        int mid = (L + R) / 2;
        mergeSort(L, mid);
        mergeSort(mid + 1, R);
        merge(L, mid, R);
    }
}
signed main() {
    cin >> N >> R >> Q;
    for (register int i = 1; i <= 2 * N; i++) {
        a[i].score = read();
        a[i].index = i;
    }
    for (register int i = 1; i <= 2 * N; i++) {
        a[i].abi = read();
    }
    for (register int i = 1; i <= R; i++) {
        mergeSort(1, 2 * N);
        for (register int j = 1; j <= 2 * N; j += 2) {
            // a[i] a[i+1]
            if (a[j].abi > a[j + 1].abi) {
                (a[j].score)++;
            } else {
                (a[j + 1].score)++;
            }
        }
    }
    mergeSort(1, 2 * N);
    cout << a[Q].index << endl;
    return 0;
}