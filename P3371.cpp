#include <iostream>
#include <cstdio>
// #define int long long
using namespace std;
const int maxn = 1e4+10;
const int inf = 0x7fffffff;
int G[maxn][maxn],n,m,s,dis[maxn],book[maxn];
int u,v,w;
int findMinx() {
  int result=0,mintmp=inf;
  for(int i=1;i<=n;i++) {
    if(book[i]) continue;
    if(dis[i] < mintmp) {
      mintmp = dis[i];
      result=i;
    }
  }
  return result;
}
signed main() {
  scanf("%d %d %d", &n,&m,&s);
  for(int i=1;i<=m;i++) {
    scanf("%d %d %d", &u,&v,&w);
    G[u][v]=w;
  }
  for(int i=1;i<=n;i++) {
    if(G[s][i]) dis[i]=G[s][i];
    else dis[i]=inf;
    if(i==s) {
      dis[i]=0;
      book[i]=1;
    }
  }
  for(int y=1;y<=n-1;y++) {
    int cur = findMinx();
    for(int i=1;i<=n;i++) {
      if(G[cur][i] && cur!=i) {
        if(dis[i]>dis[cur]+G[cur][i])
          dis[i]=dis[cur]+G[cur][i];
      }
    }
    book[cur]=1;
  }
  for(int i=1;i<=n;i++) {
    if(dis[i]==inf) {
      printf("2147483647 ");
      continue;
    }
    printf("%d ", dis[i]);
  }
  return 0;
}
