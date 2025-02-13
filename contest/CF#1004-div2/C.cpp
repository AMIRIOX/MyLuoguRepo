// 对比末尾原思路, 其实发现赛时想的已经很接近正解了
// 加油

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int ans = 9;
    for(int k = 0; k <= 9; k++) {
        string digits = to_string(n - k);

        int minyd = 0x7fffffff;
        digits = "0" + digits; // leading 0
        for(const auto &c : digits) {
            auto op = ('7' - c) % 10;
            minyd = min(minyd, op + (op < 0 ? 10 : 0));
        }
        if(k >= minyd) {
            ans = min(ans, k);
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}

/*
 * 赛时思路:

本来就有7: ans = 0

没有7:

从倒数第二位开始,

7 - b_i 或 7 - b_i + 10 (取决于7 和 b_i大小关系)
答案ans成立条件是 b_i + 1...b_n所构成的数字 > ans


 如果这一位小于7:

yx, yx + 10 * (7 - y) - (7 - y) = 7x - (7 - y),
即 x >= 7 - y, ans = 7 - y

zyx, zyx + 100 * (7 - z) - (7 - z) = 7yx - (7 - z), 
即yx >= 7 - z, ans = 7 - z

 如果这一位大于7:
yx, yx + 10 * (10 - y + 7) - (7 - y + 10), = 17x - (7 - y + 10)
还是x > 7 - y + 10, ans = 7 - y + 10

zyx, zyx + 100 * (10 - z + 7) - (7 - z + 10) = 17yx - (7 - z + 10), 
即yx >= 7 - z + 10, ans = 7 - z + 10

-----------------------

赛后补充:

只要换一下想法, 首先不要一开始就(7 - y), 想到把 999.. 转换成 10^k - 1 是正确的

先 n = n + 10*k - k, 然后调换一下, n - k + 10*k, 这样就转化为 + 10*k  
这是对于加相同数量9(比如统一+9, 或者统一+99)的k此操作, 如果9的数量不同,  
比如3次+9, 5次+99, 那就是 n = n - k + 10^a + 10^b + 10^c ..., 其中 k = a + b + c + ...

所以只需要判断令某一位 digit + 10^i 到 7 的 i 是多少

然后还是上面的思路, i 应该是 7 - y 或 7 - y + 10 (即 (7 - y) % 10, 这个结论记一下)

然后加入枚举思想(反正 k 不超过 9, 这里注意"思考答案最大值域"的思想)

就得到正解: 枚举 k, 比较 k 是否大于等于 (i = min((7 - y) % 10 for y in digits(n -k)))

计算最小 ans 即可
*/
