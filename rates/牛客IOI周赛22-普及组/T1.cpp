#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 500;
const int maxa = 200*200+10;
struct point{
  int x,y;  
  point(int _x=0, int _y=0):x(_x),y(_y) {}
  bool operator<(const point& o) {
      if(x==o.x) return y<o.y;
      else return x<o.x;
  }
}ps[maxn], ansv[maxa];
int n, ans;
double dis(point origin, point to) {
    return sqrt((to.x-origin.x)*(to.x-origin.x)+(to.y-origin.y)*(to.y-origin.y));
}
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d %d", &ps[i].x, &ps[i].y);
    }
    for(int i=1;i<=200;i++) {
        for(int j=1;j<=200;j++) {
            double dist = -1;
            point orz(i,j);
            bool ok = true;
            for(int ib=1;ib<=n;ib++) {
                if(dist!=-1) {
                    double tmd = dis(orz,ps[ib]);
                    if(tmd!=dist) { ok=false; break; }
                }else {
                    dist = dis(orz,ps[ib]);
                }
            }
            if(ok) {
                ansv[++ans].x=i;
                ansv[ans].y=j;
            }
        }
    }
    sort(ansv+1,ansv+ans+1);
    if(ans) printf("%d %d", ansv[1].x, ansv[1].y);
    return 0;
}