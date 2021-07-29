#include <cstdio>
#include <iostream>
using namespace std;
signed main() {
    int n, t = 0;  // 0 means Txxxx, 1 means Axxxx
    string a;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        if(a[i]=='1') {
            printf("%s\n",t?"Aoki":"Takahashi");
            break;
        }
        t=!t;
    }
    return 0;
}