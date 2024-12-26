#include <iostream>
#include <map>
using namespace std;
map<int, int> MAP;
int l,m,n;
int L[200010], cnt[200010];
int main() {
    cin >> l >> m >> n;
    for(int i=1;i<=l;i++) {
        cin >> L[i];
    }
    for(int i=1;i<=l;i++) 
        MAP[L[i]]=i;
    for(int i=1;i<=m;i++) {
        int x;
        cin >> x;
        cnt[MAP[x]]++;
    }
    // 略
    return 0;
}