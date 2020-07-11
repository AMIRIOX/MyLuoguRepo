#include <iostream>
using namespace std;
int tot=0;
int n = 0;
int evn[2020]={6,2,5,5,4,5,6,3,7,6};
int ev[4];
void _dfs(int level){
	for(int i=0;i<=1000;i++){
		if(n-evn[i]>=0){
			ev[level]=i;
			n -= evn[i];
			if(level==3){
				if(ev[1]+ev[2]==ev[3] && n==4) tot++;				
			}else _dfs(level+1);
			n += evn[i];
		}
	}
}
int main(){
	cin >> n;
	for(int i=10;i<=1000;i++)
		evn[i]=evn[i/10]+evn[i%10];
	_dfs(1);
	cout << tot;
	return 0;
}
