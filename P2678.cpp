#include <iostream>
//#include <algorithm>
using namespace std;
int L, N, M, a[100001];
bool check(int x) {
    int yz = 0, current=0;
    /*
    ?      0 2 11 14 17 21 25
    ?      65343245 0 0
    */
    for (int i = 1; i <= N; i++) {
        if (a[i] - a[current] < x) {
            yz++;
        }else current=i;
        if(yz>M) return false;
    }
    return yz <= M;
}
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG
    cin >> L >> N >> M;
    if(M==0) {
        cout << L << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[N + 1] = L;
    // sort(a,a+N);
    int l = 0, r = 1e8 + 1, mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid, l = mid + 1;
        } else {
            // cout << mid << "can not" << endl;
            r = mid - 1;
        }
        // cout << l << " " << r << " " << mid << endl;;
    }
    cout << ans << endl;
    return 0;
}