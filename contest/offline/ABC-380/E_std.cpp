#include<stdio.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)

//union-find
#define UFLIMIT (5<<17)
int unicnt[UFLIMIT+10];//正ならcnt、非正なら根のindex
void ufinit(int n){rep(i,0,n)unicnt[i]=1;}
int ufroot(int x){return unicnt[x]<=0?-(unicnt[x]=-ufroot(-unicnt[x])):x;}
int ufsame(int x,int y){return ufroot(x)==ufroot(y);}         //vvv
void uni(int x,int y){if((x=ufroot(x))==(y=ufroot(y)))return;if(x>y){int t=x;x=y;y=t;}unicnt[x]+=unicnt[y];unicnt[y]=-x;}
#undef UFLIMIT


int cnt[500010],color[500010];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	rep(i,1,n+2)cnt[i]=1;
	rep(i,0,n+2)color[i]=i;
	ufinit(n+2);

	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,c;
			scanf("%d%d",&x,&c);
			int L=ufroot(x);
			int size=unicnt[L];
			cnt[color[L]]-=size;
			color[L]=c;
			cnt[color[L]]+=size;
			if(color[ufroot(L-1)]==color[L])uni(L-1,L);
			if(color[ufroot(L+size)]==color[L])uni(L,L+size);
		}else{
			int c;
			scanf("%d",&c);
			printf("%d\n",cnt[c]);
		}
	}
}
