#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int maxn = 1e5+10;
signed main() {
    int cnt = 0;
    for(int i=1;i<=100000 ;i++) {
        if(100000%i==0) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;

}