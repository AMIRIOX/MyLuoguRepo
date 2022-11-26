#ifdef METH_1
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <vector>
const int maxn=1200;
using namespace std;
int a,b;
struct edge{
	int x,y,w;
}ed[200000];
int fa[maxn], ans;
int tot=0, edn=0, bger=0;
int find(int x) {
	while(x!=fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}
// vector<pair<int, int> > pth;
void kruskal() {
	sort(ed+1,ed+edn+1,[&](const edge& a, const edge& b){return a.w<b.w;});
	for(int i=1;i<=edn-bger;i++) {
		int x=find(ed[i].x), y=find(ed[i].y);
		if(x==y) continue;	
		// pth.push_back(pair<int, int>(ed[i].x, ed[i].y));
		ans+=ed[i].w;
		fa[x]=y;
		if(++tot==b-1) break;   // 0点不强制连
	}
}
int main() {
	scanf("%d %d", &a, &b);
	for(int i=1;i<=b;i++) {
		for(int j=1;j<=b;j++) {
			int k1; scanf("%d", &k1);
			if(i>=j || k1==0) continue;   // 跳过无需建的边
			ed[++edn].x=i;
			ed[edn].y=j;
			ed[edn].w=k1;
			if(k1>a) bger++;
		}
	}
	// for(int i=1; i<=b; i++) {
	// 	ed[++edn].x=0;
	// 	ed[edn].y=i;
	// 	ed[edn].w=a;
	// }
	for(int i=0;i<=b;i++) fa[i]=i;
	kruskal();
	// for(int i=0;i<pth.size(); i++) 
	// 	printf("%d->%d\n", pth[i].first, pth[i].second);
	if(tot==b-1) printf("%d\n", a+ans);
	else printf("%d\n", ans+a*(b-tot));
	return 0;
}
#endif

#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <vector>
const int maxn=1200;
using namespace std;
int a,b;
struct edge{
	int x,y,w;
}ed[200000];
int fa[maxn], ans;
int tot=0, edn=0, bger=0;
int find(int x) {
	while(x!=fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}
// vector<pair<int, int> > pth;
void kruskal() {
	sort(ed+1,ed+edn+1,[&](const edge& a, const edge& b){return a.w<b.w;});
	for(int i=1;i<=edn;i++) {
		int x=find(ed[i].x), y=find(ed[i].y);
		if(x==y) continue;	
		// pth.push_back(pair<int, int>(ed[i].x, ed[i].y));
		ans+=ed[i].w;
		fa[x]=y;
		if(++tot==b-1) break;   // 0点不强制连
	}
}
int main() {
	scanf("%d %d", &a, &b);
	for(int i=1;i<=b;i++) {
		for(int j=1;j<=b;j++) {
			int k1; scanf("%d", &k1);
			if(i>=j || k1==0) continue;   // 跳过无需建的边
			ed[++edn].x=i;
			ed[edn].y=j;
			ed[edn].w=k1;
		}
	}
	for(int i=1; i<=b; i++) {
		ed[++edn].x=0;
		ed[edn].y=i;
		ed[edn].w=a;
	}
	for(int i=0;i<=b;i++) fa[i]=i;
	kruskal();
	// for(int i=0;i<pth.size(); i++) 
	// 	printf("%d->%d\n", pth[i].first, pth[i].second);
	if(tot==b-1) printf("%d\n", a+ans);
	else printf("%d\n", ans+a*(b-tot));
	return 0;
}