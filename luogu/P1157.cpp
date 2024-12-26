#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[10001];
int visited[10001];
int n, r;
int cnt = 1;
void output(){
    for(int i=1;i<=r;i++){
        printf("%3d",a[i]);
    }
    printf("\n");
}
void dfs(int lv) {
    if (lv > r) {
        //memset(visited,0,sizeof(int)*10001);
        output();
        //memset(a,0,sizeof(int)*10001);
        return;
    }
    for(int i=a[lv-1]+1;i<=n;i++){
        //if(!visited[i])
            a[lv]=i;
        //visited[i]=1;
        dfs(lv+1);
        //visited[i]=0;
    }
}
int main() {
    scanf("%d %d", &n, &r);
    dfs(1);
    // system("pause");
    return 0;
}