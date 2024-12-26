#include <cstdio>
#include <iostream>
#include <vector>
#define I_LOVE_YOU cout << ans << endl;  // 七夕限定
#define I_AM_ALWAYS_WAITING_FOR_YOU \
    do {                            \
        cout << 0 << endl;          \
        return 0;                   \
    } while (0);  // 七夕限定
using namespace std;
const int maxn = 100010;
int stars[maxn];
int love[maxn];
int N, W, ans, maxPos;
inline int max_(int a, int b) { return a > b ? a : b; }
void counting(int stars[]) {
    love[1] = stars[1];
    for (int i = 2; i <= maxPos; i++) {
        love[i] = love[i - 1] + stars[i];
    }
}
int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        int position, cStar;
        cin >> position >> cStar;
        maxPos = max_(maxPos, position);
        stars[position] += cStar;
    }
    if (W == 0) I_AM_ALWAYS_WAITING_FOR_YOU
    counting(stars);
    // for(int i=1;i<=N;i++) {
    //     cout << love[i] << ' ';
    // }
    // cout << "---------" << endl;
    for (int i = W; i <= maxPos; i++) {
        int sum = 0;
        if (i == W)
            sum = love[i];
        else {
            sum = love[i] - love[i - W];
        }
        ans = max_(ans, sum);
        // cout << "now in " << i << ". sum=" << sum << "; ans=" << ans << endl;
    }
    I_LOVE_YOU
    return 0;
}