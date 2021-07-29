#include <iostream>
#include <cstdio>
using namespace std;
char a[120][120], ans[120][120];
string t = "yizhong";
int n;
int dirx, diry;

int main() {
    scanf("%d", &n);
    getchar();
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%1c", &a[i][j]);
            ans[i][j]='*';
        }
        getchar();
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]=='y') {
                dirx=0, diry=1;
                dfs(i,j,0);
                dirx=0, diry=-1;
                dfs(i,j,0);
                dirx=-1, diry=0;
                dfs(i,j,0);
                dirx=1, diry=0;
                dfs(i,j,0);
                dirx=-1, diry=-1;
                dfs(i,j,0);
                dirx=1, diry=-1;
                dfs(i,j,0);
                dirx=-1, diry=1;
                dfs(i,j,0);
                dirx=1, diry=1;
                dfs(i,j,0);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}