#include <bits/stdc++.h>
using namespace std;
struct zb{
    double x;
    double y;
}xy[3];
inline double dis(double x1, double y1, double x2, double y2) {
    double tmp1 = (x2 - x1) * (x2 - x1);
    double tmp2 = (y2 - y1) * (y2 - y1);
    return (double)sqrt(tmp1+tmp2);
}
int main(){
    for(int i=0;i<3;i++){
        cin >> xy[i].x;
        cin >> xy[i].y;
    }
    double A = dis(xy[0].x,xy[0].y,xy[1].x,xy[1].y);
    double B = dis(xy[0].x,xy[0].y,xy[2].x,xy[2].y);
    double C = dis(xy[2].x,xy[2].y,xy[1].x,xy[1].y);
    double sum = A+B+C;
    cout.setf(ios::fixed);
    cout << setprecision(2) << sum;
    system("pause");
    return 0;
}