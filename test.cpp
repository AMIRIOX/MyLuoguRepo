#include <cstdio>
#include <vector>
#include <queue>
#define N 105
using namespace std;
int fa[N],rd[N],Map[N][N],path[N][N],n,m;
int find_(int x) {return x==fa[x]?x:fa[x]=find_(fa[x]);}
int tppx()
{
    int ret=0,que[N<<4],l=0,r=0;
    for(int i=1;i<=n;++i) if(!rd[i]) que[++r]=i;
    for(int now;l<r;)
    {
        now=que[++l];
        if(l==r)
        {
            int i=1;
            for(i=1;i<=r;++i) if(path[now][que[i]]==0) break;
            if(i==r+1) ret++;
        }
        for(int i=1;i<=n;++i)
        if(Map[now][i])
        {
            if(rd[i])
            {
                rd[i]--;
                if(!rd[i]) que[++r]=i;
                for(int j=1;j<=r;++j) path[i][que[j]]|=path[now][que[j]];//==if(path[now][que[j]]) path[i][que[j]]=1;
            }
        }
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int x,y,i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        fa[find_(y)]=find_(x);
        rd[y]++;
        Map[x][y]=1;
    }
    int k=0;
    for(int i=1;i<=n;++i) {if(fa[i]==i) k++;path[i][i]=1;} 
    if(k>1) printf("0\n");
    else printf("%d\n",tppx());
    return 0;
}
