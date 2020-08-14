#include <iostream>
#include <vector>
using namespace std;
const int maxn=100010;
vector<int> gr[maxn];
int vis[maxn],len[maxn];
int dfs(int x) {
    if(vis[x]) return vis[x];
    for(int i=0,sz=gr[x].size();i<sz;i++) {
        vis[x]=max(vis[x],dfs(gr[x][i]));
    }
    vis[x]+=len[x];
    return vis[x];
}
int main() {
    int n,x,y,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> x >> len[i];
        while(cin >> y) {
            if(!y) break;
            else gr[y].push_back(x);
        }
    }
    for(int i=1;i<=n;i++) {
        ans=max(ans,dfs(i));
    }
    cout << ans << endl;
    return 0;
}