#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n; 
    cin >> n;
    int res = 0x3f3f3f3f, x, y;
    for(int i = 1; i <= 13; i++)
    {
        if(i==2)continue;
        int t = 1;
        for(int j = 1; j <= i; j++)
            t *= j;
        t--;
        int k;
        if(t==0) k = 1;
        else  k = n/t;
        if(k != 2) 
        {
            int aa = abs(t * k - n);
            if(aa < res)  res = aa, x = i, y = k;
        }
        if(k != 1) 
        {
            int aa = abs(t * (k+1) - n);
            if(aa < res)  res = aa, x = i, y = k+1;
        }
    }
    cout << x <<  " " << y << endl;
}
