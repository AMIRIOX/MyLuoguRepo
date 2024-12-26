#include <iostream>
#include <cstdio>
#define maxn 10001
using namespace std;
int R,C,K,ans;
char map[maxn][maxn];
void dfs(int ar,int x,int y,int last){
    if(ar==K) {
        ans++;
        return;
    }
    if(x+1<=R && map[x+1][y]=='.' && last==1)
        dfs(ar+1,x+1,y,1);
    if(y+1<=C && map[x][y+1]=='.' && last==2)
        dfs(ar+1,x,y+1,2);
    // if(x+1<=R && map[x+1][y]=='.' && last==2)
    //     dfs(1,x+1,y,2);
    // if(y+1<=C && map[x][y+1]=='.' && last==1)
    //     dfs(1,x,y+1,1);
}
signed main(){
    scanf("%d%d%d",&R,&C,&K);
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin >> map[i][j];

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(map[i][j]=='.'){
                dfs(1,i,j,1);
                dfs(1,i,j,2);
            }
    //system("pause");
    if(K==1) ans/=2;
    printf("%d",ans);
    return 0;
}