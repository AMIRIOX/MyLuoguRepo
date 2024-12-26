#include <iostream>
#include <cstdio>
using namespace std;

int n,m;

long long zfx,jx,cfx;
int main(){
    scanf("%d %d",&n,&m);
    //* 以i,j为右下角的正方形有min(i,j)个;
    //* 以i,j为右下角的矩形有i*j个;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            zfx+=min(i,j);
            jx+=i*j;
        }
    }
    cfx=jx-zfx;
    printf("%lld %lld",zfx,cfx);
    system("pause");
    return 0;
}