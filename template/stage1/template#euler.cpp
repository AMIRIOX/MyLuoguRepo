#include <iostream>
#include <stack>
#include <vector>
#define re register
using namespace std;
const int maxn = 1000;

stack<pair<int, int> > ways;
vector<int> gr[maxn];
int vis[maxn][maxn];
void euler(int u) {
    for (int i = 0; i < gr[u].size(); i++) {
        if (int v = gr[u][i]; !vis[u][v]) {
            vis[u][v] = vis[v][u] = 1;
            euler(v);
            ways.push(pair<int, int>(u, v));
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    euler(1);
    while(!ways.empty()) {
        pair<int,int> p = ways.top();
        ways.pop();
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}