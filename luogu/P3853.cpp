#include <algorithm>
#include <iostream>
using namespace std;
int L, N, K, a[100001];
bool check(int x) {
    int lb = 0;
    if (a[N - 1] != 0 && a[N - 1] - 0 > x) {
        int c = a[N - 1] - 0;
        lb += c / x;  // cout << "..";
        if (c % x == 0) lb--;
    }
    if (a[0] < N && N - a[0] > x) {
        int c = N - a[0];
        lb += c / x;  // cout << "..";
        if (c % x == 0) lb--;
    }
    //! 模拟的是路长, 不是a[i]
    for (int i = 0; i < N; i++) {
        if (i + 1 > N) break;
        int dis = a[i] - a[i + 1];
        if (dis > x) {
            lb += dis / x;  // cout << "..";
            if (dis % x == 0) lb--;
            if (lb > K) return false;
        }
        //* 3
        //* 1 2 3 4 5 6 7 8 9 10
        //* 1 10
        // else break;
    }
    // cout << lb << endl;
    return lb <= K;
}
int main() {
    cin >> L >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N, std::greater<int>());
    // for(int i=0;i<N;i++) cout << '('<< a[i] <<") " << endl;
    int l = 0, r = 1e8 + 1, ans;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid, r = mid;
            // cout << "check "<<mid << "suc.";
        } else {
            l = mid + 1;
        }
        // cout << l << " " << r << endl;
        // cout << ans << endl;
    }
    cout << ans;
    // cout << "end!";
    return 0;
}