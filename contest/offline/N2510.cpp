// 顺子
// c[a] c[b] c[c]
// 
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int a[10010]; //, c[10000010];
map<int, int> c;
bool ans=true;
int main() {
    int n,w;
    cin >> n;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        c[a[i]]++;
    }
    cin >> w;
    sort(a+1,a+n+1);
    if(n%w) {
        cout << "false" << endl;
        return 0;
    }
    for(int i=1;i<=n;i++) {
        if(i+w<=n && a[i]!=0) {
            for(int j=i; j<=i+w; j++) {
                c[a[j]]-=a[i];
                if(a[j]<0) {ans=false; break;}
            }
        }
        if(ans==false) break;
    }
    cout << (ans?"true":"false");
    return 0;
}