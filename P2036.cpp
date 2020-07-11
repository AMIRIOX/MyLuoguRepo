#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int S[20];
int B[20];
int ans = INT_MAX;
void dfs(int lv, int a, int b){
    if(lv==n){
        if(a==1 && b==0){
            return;
        }else{
            int tmp=a-b;
            tmp = tmp>=0?tmp:-tmp;
            if(tmp<ans) ans=tmp;
        }
    }else{
        dfs(lv+1,a*S[lv],b+B[lv]);
        dfs(lv+1,a,b);
    }
}
int main(){
scanf("%d",&n);
    //system("pause");
    for(int i=0;i<n;i++){
        scanf("%d%d",&S[i],&B[i]);
    }
    dfs(0,1,0);
    printf("%d",ans);
    return 0;
}