#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define maxn 100010
#define META an[i]
using namespace std;
int m,n,am[maxn],an[maxn];
int l,r,mid,tot;
int main() {
    cin >> m >> n;
    for(int i=0;i<m;i++) cin >> am[i];
    for(int i=0;i<n;i++) cin >> an[i];
    sort(am,am+m);
    for(int i=0;i<n;i++) {
        l=0,r=m;
        // mid = l+(r-l)/2;
        while(l<r) {
            mid = l+(r-l)/2;
            if(am[mid]<=META) {
                l=mid+1;
            }else {
                r=mid;
            }
            //cout << l <<" "<< r << endl;
        }
        if(META<am[0]) {
            tot+=am[0]-META;
        }else{
            l--;
            tot+= min(abs(am[l]-META),abs(am[l+1]-META));
        }
    }
    cout << tot;
    return 0;
}