#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int ans = 0, a[maxn], tmp[maxn], n;
void merge(int L, int mid, int R) {
    int i = L, j = mid + 1;
    int cnt = 1;
    while (i <= mid && j <= R) {
        if (a[i] <= a[j]) {
            tmp[cnt++] = a[i++];
        } else {
            ans += mid - i + 1;
            tmp[cnt++] = a[j++];
        }
    }
    while (i <= mid) tmp[cnt++] = a[i++];
    while (j <= R) tmp[cnt++] = a[j++];
    cnt=1;
    while (L <= R) a[L++] = tmp[cnt++];
}
void mergeSort(int L, int R) {
    if (L < R) {
        int mid = (L + R) / 2;
        mergeSort(L, mid);
        mergeSort(mid + 1, R);
        merge(L, mid, R);
    }
}
signed main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    mergeSort(1,n);
    // for(int i=1;i<=n;i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    cout << ans << endl;
    return 0;
}