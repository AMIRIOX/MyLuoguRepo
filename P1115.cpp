#include <iostream>
#define int long long
using namespace std;
const int inf = 0x7fffffff;
int n, c, /*pre[100010], */ ans = -inf, sum;
signed main() {
    cin >> n;
    for(int i=1; i<=n ;i++) {
        cin >> c;
        if(i==1) sum = ans = c;
        else {
            sum = sum>0?sum:0;
            sum += c;
            ans = max(sum, ans);
        }
    }
    cout << ans << endl;
    return 0;
}