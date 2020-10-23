#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 1e6+1;
int bs,a,b,c,d,e,f;
int isa, fsx;
signed main() {
    cin >> bs >> a >> b >> c >> d >> e >> f >> isa >> fsx;
    int zf = a+b+c+d+e+f+bs;
    if(isa) zf+=5;
    if(a)zf++;
    if(b)zf++;
    if(c)zf++;
    if(d)zf++;
    if(e)zf++;
    if(f)zf++;

    if(zf+50>fsx) cout <<"AKIOI";
    else cout << "AFO";
    return 0;
}