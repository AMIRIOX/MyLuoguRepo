#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int a[2000001];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+m);
    for(int i=0;i<m;i++){
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}