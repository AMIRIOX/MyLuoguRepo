#include <iostream>
#include <algorithm>
using namespace std;
int N,C,a[100010],ans;
bool P(int x) {
    int last=-1e9, ard=0;
    for(int i=0;i<N;++i) {
        if(a[i]-last >= x) {
            ard++, last=a[i];
        }
    }
    return ard>=C;
}
int main() {
    cin >> N >> C;
    for(int i=0;i<N;++i) {
        cin >> a[i];
    }
    sort(a,a+N);
    int l=0,r=1e9,mid;
    while(l<=r) {
        if(P(mid=l+(r-l)/2)) {
            ans=mid, l=mid+1;
        }else {
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}