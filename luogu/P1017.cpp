#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100010;
//TODO: 如果爆int, 就typedef long long LL 或define int long long

inline long long power(int di, int zhi) {
    long long ans=1;
    for(int i=1;i<=zhi;i++) {
        ans*=di;
    }
    return ans;
}
int main() {
    // cout << power(2,3);
    string number;
    cin >> number;
    signed int base;
    cin >> base;
    long long ans = 0;

    int cur = number.size()-1;
    // cout << cur << endl;
    for(int i=0;i<number.size();i++) {
        ans+=((number[i]-'0')*power(base,cur));
        // printf("%c*(%d)^%d+",number[i],base,cur);
        cur--;
    }
    cout << ans << endl;
    return 0;
}