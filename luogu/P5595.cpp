#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6+1;
string x,a,b;
signed main() {
    cin >> x;
    reverse(x.begin(),x.end());
    for(register int i=x.length()-1;i>=0;i--) {
        char now = x[i];
        if(now=='X') {
            a+="9";
            b+="0";
        }else if(now=='Y'){
            a+="0";
            b+="9";
        }else if(now=='Z') {
            if(a!=b) {
                cout << -1;
                return 0;
            }
            a+="0";
            b+="0";
        }
    }
    for(int i=a.length()-1;i>=0;i--) {
        printf("%c",a[i]);
    }
    printf("\n");
    for(int i=b.length()-1;i>=0;i--) {
        printf("%c",b[i]);
    }
    return 0;
}