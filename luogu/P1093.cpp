#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
struct IEE
{
    /* data */
    int ind;
    int yw;
    int sx;
    int yy;
    int sum;
    void comSum(){
        sum=yw+sx+yy;
    }
    bool operator>(const IEE& b) const{
        if(sum!=b.sum) return sum > b.sum;
        else if(yw!=b.yw) return yw > b.yw;
        else return ind < b.ind;
    }
    bool operator<(const IEE& b) const{
        if(sum!=b.sum) return sum < b.sum;
        else if(yw!=b.yw) return yw < b.yw;
        else return ind > b.ind;
    }
}ee[100001];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ee[i].ind=i+1;
        scanf("%d",&ee[i].yw);
        scanf("%d",&ee[i].sx);
        scanf("%d",&ee[i].yy);
        ee[i].comSum();
    }
    sort(ee,ee+n);
    int cnt = 5;
    for(int i=n-1;cnt;i--,cnt--){
        printf("%d ",ee[i].ind);
        printf("%d\n",ee[i].sum);
    }
    system("pause");
    return 0;
}