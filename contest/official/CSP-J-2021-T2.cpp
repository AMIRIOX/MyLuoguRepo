/* // 76pts
#include <iostream>
#include <cstdio>
using namespace std;
int a[10000];
int n, Q;
int main() {
	scanf("%d %d", &n, &Q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	while(Q--) {
		int cmd, x, v;
		scanf("%d", &cmd);
		if(cmd==1) {
			scanf("%d %d", &x, &v);
			a[x]=v;
		}else {
			scanf("%d", &x);
			// �ҵ���a[x]С�����ĸ���+��xǰ��a[x]��ȵ����ĸ���
			int cnt=0;
			for(int i=1;i<=n;i++) {
				if(a[i]<a[x]) cnt++;
				if(a[i]==a[x] && i<x) cnt++;
			}
			printf("%d\n", cnt+1);
		}	
	}
	return 0;
}*/


/* // 36pts
#include <iostream>
#include <cstdio>
using namespace std;
int a[10000];
int n, Q;
int tag[10000];
void inup(int xp=-1) {
	//��ÿ��i�ҵ���a[i]С�����ĸ���+��xǰ��a[i]��ȵ����ĸ���
	// del-> a[i]<xp �� a[i]==a[xp] && i<xp�Ĳ��ø���
	for(int i=1; i<=n; i++) {
		// if(xp!=-1 && (a[i]<xp || (a[i]==a[xp] && i<xp))) continue; 
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(a[j]<a[i]) cnt++;
			if(a[j]==a[i] && j<i) cnt++; 
		}
		tag[i]=cnt;
	}
}
int main() {
	scanf("%d %d", &n, &Q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	inup();
	while(Q--) {
		int cmd, x, v;
		scanf("%d", &cmd);
		if(cmd==1) {
			scanf("%d %d", &x, &v);
			a[x]=v;
			inup(x);
		}else {
			scanf("%d", &x);	
			printf("%d\n", tag[x]+1);
		}	
	}
	return 0;
}*/

 // 0pts
#include <iostream>
#include <cstdio>
using namespace std;
int a[10000];
int n, Q;
int tag[10000];
int less_t[10000];
void init() {
	for(int i=1;i<=n;i++) {
		int cnt=0, cntv=0;
		for(int j=1;j<=n;j++) {
			if(a[j]<a[i]) cntv++;
			if(a[j]<a[i] || (a[j]==a[i] && j<i)) cnt++;
		}
		tag[i]=cnt;
		less_t[i]=cntv;
	}
}
void inup(int xp, int ori) {
	//��ÿ��i�ҵ���a[i]С�����ĸ���+��xǰ��a[i]��ȵ����ĸ���
	/*int cnt = 0;
	for(int i=1;i<=n;i++) {
		if(a[xp]>a[i] || (a[i]==a[xp] && i<xp)) cnt++;
	}
	tag[xp]=cnt;
	for(int i=1; i<=n; i++) {
		if(i==xp) continue;
		if(a[xp]-ori>0) {
			if((a[i]>ori && a[i]<a[xp]) || (a[i]==a[xp] && xp>i)) tag[i]--;
			else if(a[i]==ori && xp<i) tag[i]--;
		}else if(a[xp]-ori<0) {
			if((a[i]<ori && a[i]>a[xp]) || (a[i]==a[xp] && xp>i)) tag[i]++;
			else if(a[i]==ori && xp<i) tag[i]++;
		}
	}*/
	for(int i=1;i<=n;i++) {
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(a[i]>a[j] || (a[i]==a[j] && j<i)) cnt++;
		}
		tag[i]=cnt;
	}
}
int main() {
	scanf("%d %d", &n, &Q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	init();
	while(Q--) {
		int cmd, x, v;
		scanf("%d", &cmd);
		if(cmd==1) {
			scanf("%d %d", &x, &v);
			int ori=a[x];
			a[x]=v;
			inup(x, ori);
		}else {
			scanf("%d", &x);	
			printf("%d\n", tag[x]+1);
		}	
	}
	return 0;
}


