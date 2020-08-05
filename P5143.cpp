#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <initializer_list>
using namespace std;

int n;
struct point{
    int x,y,z;
    bool operator<(const point& b){
        return z < b.z;
    }
    bool operator>(const point& b){
        return z > b.z;
    }
    point(int xi=0, int yi=0, int zi=0){
        x=xi,y=yi,z=zi;
    }
}m[10001];
double distance(point a, point b){
    //* (Xi-Xj)2+(Yi-Yj)2+(Zi-Zj)2
    double ai = (double(a.x-b.x))*double((a.x-b.x));
    double bi = double((a.y-b.y))*double((a.y-b.y));
    double ci = double((a.z-b.z))*double((a.z-b.z));
    double di = ai+bi+ci;
    return sqrt(di);
}
int main(){
    double dis;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&m[i].x,&m[i].y,&m[i].z);
    }
    sort(m,m+n);
    for(int i=1;i<n;i++){
        dis+=distance(m[i],m[i-1]);
    }
    printf("%.3f",dis);
    system("pause");
    return 0;
}