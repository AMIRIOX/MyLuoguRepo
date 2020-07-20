#include <iostream>
#include <algorithm>
using std::endl;
using std::cout;
using std::sort;
using std::cin;
struct milk {
    int pi;
    int ai;
}a[10005];
int n,m,ans;
bool cmp(milk a, milk b) {
    if(a.pi != b.ai) return a.pi < b.pi;
    else return a.pi > b.pi;
}
int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> a[i].pi;
        cin >> a[i].ai;
    }
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++) {
        if(n==0) break;
        if(a[i].ai <= n){
            ans+=a[i].ai*a[i].pi;
            n-=a[i].ai;
        }else {
            ans+=a[i].pi*n;
            n=0;
        }
    }
    cout << ans;
    return 0;
}
