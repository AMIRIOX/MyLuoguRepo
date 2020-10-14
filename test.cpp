#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int a[maxn];

void merge(int L, int mid, int R) {
    // 1 3 4 7 8   [L,mid]
    // 2 3 4 5 6   [mid+1,R]
    cout << "a merge begin..." << endl;
    int temp[maxn];
    int i = L;
    int j = mid + 1;
    int cnt = 1;
    cout << "here " << L << ' ' << mid << ' ' << R << endl;
    while (i <= mid && j <= R) {
        printf("the a[%lld] is %lld, the b[%lld] is %lld\n", i, a[i], j, a[j]);
        if (a[i] <= a[j]) {
            cout << "cnt=" << cnt << endl;
            temp[cnt++] = a[i++];
        }
        cout << "?" << endl;
        if (a[j] < a[i]) {
            temp[cnt++] = a[j++];
        }
        cout << "temp: " << endl;;
        for(int i=1;i<cnt;i++) {
            cout << temp[i] << ' ';
        }
        cout << endl;
    }
    while(i<=mid) {
        temp[cnt++]=a[i++];
    }
    while(j<=R) {
        temp[cnt++]=a[j++]; 
    }
    cnt=1;
    int tm = L;
    while(L<=R) {
        a[L++]=temp[cnt++];
    }
    for(int i=tm;i<=R; i++) {
        cout << i << ':' << a[i] << ' ';
    }
    cout << "\na merge..." << endl;
}

// [L,R]
void mergeSort(signed L, signed R) {
    if (L < R) {
        cout << "a sort to be two part..." << endl;
        int mid = (L+R)/2;
        mergeSort(L, mid);
        mergeSort(mid + 1, R);
        merge(L, mid, R);
    }
}

signed main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    mergeSort(1, n);
    for(int i=1;i<=n;i++) {
        cout << a[i] << ' ';
    }
    return 0;
}