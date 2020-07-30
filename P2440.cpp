#include <iostream>
#define int long long
using namespace std;
int N, K, a[100010];
bool check(int x) {
    signed cnt = 0;
    for (register int i = 0; i < N; ++i) {
        int tmp = a[i];
        // while(tmp>=x) {
        //     if(tmp%x==0){
        //         cnt+=tmp/x;
        //         break;
        //     }
        //     tmp-=x;
        //     cnt++;
        // }
        cnt += tmp / x;
    }
    return cnt >= K;
}
signed main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    // cout << "???";
    int l = 0, r = 1e8 + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        // cout << mid << endl;
    }
    l--;
    if (l == -1)
        cout << 0 << endl;
    else
        cout << l << endl;
}