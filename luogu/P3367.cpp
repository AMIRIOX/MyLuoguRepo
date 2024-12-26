#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6+1;
int fa[maxn],n,m;
int findx(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findx(fa[x]);
}
void join(int a, int b) {
    int a1=findx(a),b1=findx(b);
    if(a1!=b1)fa[a1]=b1;
}
void init(int N) {
    for(int i=1;i<=N;i++) {
        fa[i]=i;
    }
}
signed main() {
    int opt,X,Y;
    cin >> n >> m;
    init(n);
    for(int i=1;i<=m;i++) {
        cin >> opt >> X >> Y;
        if(opt==1) {
            join(X,Y);
        }else {
            if(findx(X) == findx(Y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}