#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int maxn = 1000;
int minn = 0;
int s1,s2,s3,s4;
int a[maxn],b[maxn],c[maxn],d[maxn];
int __time = 0,right=0,left=0;
int* p;
void dfs(int lv,int size,int _left,int _right){
    if(lv==size+1){
        minn=min(minn,(_right>_left ? _right : _left));
        return;
    }else{
        dfs(lv+1,size,_left+p[lv+1],_right);
        dfs(lv+1,size,_left,_right+p[lv+1]);

    }
}
int main(){
    scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
    for(int i=0;i<s1;i++){
        scanf("%d",&a[i]);
        
    }
    minn = INT_MAX;
        p=a;
        dfs(-1,s1,0,0);
        __time+=minn;
    for(int i=0;i<s2;i++){
        scanf("%d",&b[i]);
        
    }
    minn = INT_MAX;
        p=b;
        dfs(-1,s2,0,0);
        __time+=minn;
    for(int i=0;i<s3;i++){
        scanf("%d",&c[i]);
        
    }
    minn = INT_MAX;
        p=c;
        dfs(-1,s3,0,0);
        __time+=minn;
    for(int i=0;i<s4;i++){
        scanf("%d",&d[i]);
        
    }
    p=d;
        minn = INT_MAX;
        dfs(-1,s4,0,0);
        __time+=minn;
    printf("%d",__time);
    //system("pause");
    return 0;
}