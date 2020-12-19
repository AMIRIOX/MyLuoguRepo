#include <iostream>
using namespace std;
const int maxn = 10001;
int a, N, M, cnt, ans = 1;
int main() {
    cin >> N >> M;
    bool processed = false;
    for(int i=1; i<=N; i++) {
        cin >> a;
        /*
            5 6
            4 2 4 5 1
        */
        if(cnt + a > M) {
            ans++;
            cnt = a;
        }else {
            cnt+=a;
        }
    }

    cout << ans;
    return 0;
}
