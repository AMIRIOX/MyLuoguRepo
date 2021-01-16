#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define mid (l+r)/2
using namespace std;
const int mod=998244353;
const int mod1=1e9+7;
int n,m,h,s,cnt,hd[200005];
bool vis[200005];
struct node{
    int to,next,id,type;
}e[4000005];
int read(){
    int f=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){f=f*10+ch-'0';ch=getchar();}
    return f*w;
}
void addedge(int x,int y,int z,int w){
    e[++cnt]=(node){y,hd[x],z,w};
    hd[x]=cnt;
}
int qpow(int x,int y){
    int ans=1;
    while(y){if(y&1) ans=ans*x%mod;x=x*x%mod;y>>=1;}
    return ans;
}
int rt[400005],ls[60000005],rs[60000005],tot,sum[60000005],v[4000005],t[4000005],b[60000005];
void build(int &now,int l,int r){
    now=++tot;if(l==r) return;
    build(ls[now],l,mid),build(rs[now],mid+1,r);
}
void modify(int &now,int pre,int l,int r,int pos,int k){
    now=++tot;
    sum[now]=(sum[pre]+k*v[pos])%mod1,ls[now]=ls[pre],rs[now]=rs[pre];
    if(l==r){
        if(k==1) b[now]=1;
        return;
    }
    if(pos<=mid) modify(ls[now],ls[pre],l,mid,pos,k);
    else modify(rs[now],rs[pre],mid+1,r,pos,k);
}
int cmp(int x,int y,int l,int r){
    if(l==r) return b[x]<b[y];
    if(sum[rs[x]]==sum[rs[y]]) return cmp(ls[x],ls[y],l,mid);
    else return cmp(rs[x],rs[y],mid+1,r);
}
bool compare(int x,int y){
    if((int)abs(sum[rt[x]]-sum[rt[y]])<2000000) return sum[rt[x]]+t[x]<sum[rt[y]]+t[y];
    return cmp(rt[x],rt[y],0,m);
}
int solve(int now,int l,int r){
    if(l==r){if(sum[now]) return qpow(2,l);return 0;}
    return (solve(ls[now],l,mid)+solve(rs[now],mid+1,r))%mod;
}
struct Node{
    int pos;
    bool operator < (const Node &a) const{return compare(a.pos,pos);}
};
void dijkstra(){
    priority_queue<Node> q;
    q.push((Node){h});
    build(rt[h],0,m);
    while(!q.empty()){
        Node now=q.top();
        q.pop();
        int x=now.pos;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=hd[x];i;i=e[i].next){
            int to=e[i].to;
            if(e[i].type==0){
                if(!rt[to]){
                    t[to]=t[x]+1;
                    modify(rt[to],rt[x],0,m,0,0);
                    q.push((Node){to});
                }
                else{
                    t[to+n]=t[x]+1;
                    modify(rt[to+n],rt[x],0,m,0,0);
                    if(compare(to+n,to)){
                        rt[to]=rt[to+n];
                        t[to]=t[x]+1;
                        q.push((Node){to});
                    }
                }
            }
            else{
                if(!rt[to]){
                    t[to]=t[x];
                    modify(rt[to],rt[x],0,m,e[i].id,1);
                    q.push((Node){to});
                }
                else{
                    t[to+n]=t[x];
                    modify(rt[to+n],rt[x],0,m,e[i].id,1);
                    if(compare(to+n,to)){
                        rt[to]=rt[to+n];
                        t[to]=t[x];
                        q.push((Node){to});
                    }
                }
            }
        }
    }
}
signed main(){
    freopen("return.in","r",stdin);
    freopen("return.out","w",stdout);
    n=read(),m=read(),h=read(),s=read();
    v[0]=1;
    for(int i=1;i<=m;i++) v[i]=v[i-1]*2%mod1;
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        addedge(x,y,i,0),addedge(y,x,i,1);
    }
    dijkstra();
    if(!vis[s]){
        puts("Impossible");
        return 0;
    }
    else{
        printf("%lld\n",(solve(rt[s],0,m)+t[s])%mod);
    }
    return 0;
}
