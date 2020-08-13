#include <iostream>
#include <vector>
#define MAXN 100010 
using namespace std;
vector<int> gr[MAXN];
int ans[MAXN];
void getAnser(int x,int v) {
    ans[x]=v;
    for(int i=0;i<gr[x].size();i++) {
        if(ans[gr[x][i]]==0)
            getAnser(gr[x][i],v);
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        gr[v].push_back(u);   //反向建边
    }
    for(int i=n;i>=0;i--) {
        if(ans[i]==0) getAnser(i,i);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
}