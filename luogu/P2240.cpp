#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct jb{
    int m;
    int v;
};
bool cmp(jb a, jb b){
    //* a.v/a.m > b.v/b.m
    //? a.v*b.m > b.v*a.m
    return ((a.v*b.m) > (b.v*a.m));
}
signed main(){
    jb bb[100001];
    int n,size;
    cin >> n >> size;
    for(int i=0;i<n;i++){
        cin >> bb[i].m;
        cin >> bb[i].v;
    }
    sort(bb,bb+n,cmp);
    int t_size = size;
    double ans=0.0;
    for(int i=0;i<n;i++){
        if(bb[i].m<t_size){
            t_size-=bb[i].m;
            ans+=bb[i].v;
        }else {
            double vi = double(bb[i].v)/double(bb[i].m);
            double sy = (double)t_size;
            ans+=vi*sy;
            break;
        }
    }
    printf("%.2f",ans);
    return 0;
}