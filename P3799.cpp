#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int sz[1000001];
int ans = 0;
int already[10000];
bool isg(int a, int b, int c) {
    //* 判断正三角形
    if (a==b && b==c && a==c)
        return true;
    else
        return false;
}
bool isg(int a,int b,int c,int d){
    bool ba = isg(a+b,c,d);
    bool bb = isg(a+c,b,d);
    bool bc = isg(a+d,c,b);
    if(ba || bc || bb) return true;
    else return false;
}
signed main() {
    int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &sz[0]);
    }
    sort(sz,sz+n);
    for(int i=1;i<=sz[n-1];i++){
        
    }
    
    printf("%lld",ans%1000000007);
    return 0;
}