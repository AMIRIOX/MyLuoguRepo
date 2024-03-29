/*#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 12200;
int filled[maxn][maxn];
int k, x, y;
void dog(int _x, int _y, int n, int gx, int gy) {
    // 思路：
    //
    //  如果当前方块是2*2的，把没填的那三个填好
    //  否则分成四个小方块，把没有公主的三个方块靠近中心点的格子铺上,
    //  将铺上的格子作为公主格子继续递归分治
    //
    if (n == 2) {
        if (filled[_x][_y]) {
            printf("%lld %lld %lld\n", _x + 1, _y, 1);
            printf("%lld %lld %lld\n", _x, _y + 1, 1);
            printf("%lld %lld %lld\n", _x + 1, _y + 1, 1);
        } else if (filled[_x + 1][_y]) {
            printf("%lld %lld %lld\n", _x, _y, 2);
            printf("%lld %lld %lld\n", _x, _y + 1, 2);
            printf("%lld %lld %lld\n", _x + 1, _y + 1, 2);

        } else if (filled[_x][_y + 1]) {
            printf("%lld %lld %lld\n", _x, _y, 3);
            printf("%lld %lld %lld\n", _x + 1, _y, 3);
            printf("%lld %lld %lld\n", _x + 1, _y + 1, 3);
        } else {
            printf("%lld %lld %lld\n", _x, _y, 4);
            printf("%lld %lld %lld\n", _x + 1, _y, 4);
            printf("%lld %lld %lld\n", _x, _y + 1, 4);
        }
        return;
    }
    if (gx <= _x + n / 2 && gy <= _y + n / 2) {  // TODO
        filled[_x + n / 2 + 1][_y + n / 2] = 1;
        printf("%lld %lld %lld\n", _x + n / 2 + 1, _y + n / 2, 1);
        filled[_x + n / 2][_y + n / 2 + 1] = 1;
        printf("%lld %lld %lld\n", _x + n / 2, _y + n / 2 + 1, 1);
        filled[_x + n / 2 + 1][_y + n / 2 + 1] = 1;
        printf("%lld %lld %lld\n", _x + n / 2 + 1, _y + n / 2 + 1, 1);
        dog(_x, _y, n / 2, gx, gy);
        dog(_x + n / 2, _y, n / 2, _x + n / 2 + 1, _y + n / 2);
        dog(_x, _y + n / 2, n / 2, _x + n / 2, _y + n / 2 + 1);
        dog(_x + n / 2, _y + n / 2, n / 2, _x + n / 2 + 1, _y + n / 2 + 1);
    } else if (gx > _x + n / 2 && gy <= _y + n / 2) {
        filled[_x + n / 2][_y + n / 2] = 1;
        printf("%lld %lld %lld\n", _x + n / 2, _y + n / 2, 2);
        filled[_x + n / 2][_y + n / 2 + 1] = 1;
        printf("%lld %lld %lld\n", _x + n / 2, _y + n / 2 + 1, 2);
        filled[_x + n / 2 + 1][_y + n / 2 + 1] = 1;
        printf("%lld %lld %lld\n", _x + n / 2 + 1, _y + n / 2 + 1, 2);
        dog(_x, _y, n / 2, _x + n / 2, _y + n / 2);
        dog(_x + n / 2, _y, n / 2, gx, gy);
        dog(_x, _y + n / 2, n / 2, _x + n / 2, _y + n / 2 + 1);
        dog(_x + n / 2, _y + n / 2, n / 2, _x + n / 2 + 1, _y + n / 2 + 1);
    } else if (gx <= _x + n / 2 && gy > _y + n / 2) {
        filled[_x + n / 2][_y + n / 2] = 1;
        printf("%lld %lld %lld\n", _x + n / 2, _y + n / 2, 3);
        filled[_x + n / 2 + 1][_y + n / 2] = 1;
        printf("%lld %lld %lld\n", _x + n / 2 + 1, _y + n / 2, 3);
        filled[_x + n / 2 + 1][_y + n / 2 + 1] = 1;
        printf("%lld %lld %lld\n", _x + n / 2 + 1, _y + n / 2 + 1, 3);
        dog(_x, _y, n / 2, _x + n / 2, _y + n / 2);
        dog(_x + n / 2, _y, n / 2, _x + n / 2 + 1, _y + n / 2);
        dog(_x, _y + n / 2, n / 2, gx, gy);
        dog(_x + n / 2, _y + n / 2, n / 2, _x + n / 2 + 1, _y + n / 2 + 1);

    } else {
        filled[_x + n / 2][_y + n / 2] = 1;
        printf("%lld %lld %lld\n", _x + n / 2, _y + n / 2, 1);
        filled[_x + n / 2 + 1][_y + n / 2] = 1;
        printf("%lld %lld %lld\n", _x + n / 2 + 1, _y + n / 2, 1);
        filled[_x + n / 2][_y + n / 2 + 1] = 1;
        printf("%lld %lld %lld\n", _x + n / 2, _y + n / 2 + 1, 1);
        dog(_x, _y, n / 2, _x + n / 2, _y + n / 2);
        dog(_x + n / 2, _y, n / 2, _x + n / 2 + 1, _y + n / 2);
        dog(_x, _y + n / 2, n / 2, _x + n / 2, _y + n / 2 + 1);
        dog(_x + n / 2, _y + n / 2, n / 2, gx, gy);
    }
}
signed main() {
    scanf("%lld %lld", &k, &x, &y);
    filled[x][y] = 1;
    dog(1, 1, (int)pow(2, k), x, y);
    return 0;
}*/

#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
// #define   (printf("fuck execute here\n"));

bool cxkpr(int lx, int ly, int k1, int prx, int pry){
	int bc=pow(2,k1-1)-1;
	if(prx>=lx && prx<=lx+bc && pry>=ly && pry<=ly+bc) return true;
	else return false;
}
// int a[2048][2048];
void fill(int k, int px, int py, int prx, int pry) {
	if(k==0) return;
	int bc=pow(2,k-1);
	if(cxkpr(px,py,k,prx,pry)) {
 
		printf("%lld %lld %lld\n", px+bc,py+bc , 1);
		fill(k-1, px, py, prx, pry);
		fill(k-1, px+bc, py+bc, px+bc, py+bc);
		fill(k-1, px, py+bc, px+bc-1, py+bc);
		fill(k-1, px+bc, py, px+bc, py+bc-1);	
	}else if(cxkpr(px+bc, py+bc, k, prx,pry)) {
 		//if(px==1 && py==1) { cout << k << endl; }
		printf("%lld %lld %lld\n", px+bc-1,py+bc-1 , 4);
		fill(k-1, px, py, px+bc-1, py+bc-1);
		fill(k-1, px+bc, py+bc, prx, pry);
		fill(k-1, px, py+bc, px+bc-1, py+bc);
		fill(k-1, px+bc, py, px+bc, py+bc-1);	

	}else if(cxkpr(px+bc, py, k, prx, pry)) {	
 
		printf("%lld %lld %lld\n", px+bc-1,py+bc , 3);
		fill(k-1, px, py, px+bc-1, py+bc-1);
		fill(k-1, px+bc, py+bc, px+bc, py+bc);
		fill(k-1, px, py+bc, px+bc-1, py+bc);
		fill(k-1, px+bc, py, prx, pry);
	}else if(cxkpr(px, py+bc, k, prx, pry)) {
 
		printf("%lld %lld %lld\n", px+bc,py+bc-1 , 2);
		fill(k-1, px, py, px+bc-1, py+bc-1);
		fill(k-1, px+bc, py+bc, px+bc, py+bc);
		fill(k-1, px, py+bc, prx, pry);
		fill(k-1, px+bc, py, px+bc, py+bc-1);			
	}	
}
using namespace std;
signed main() {
	int k, x, y;
	cin >> k >> x >> y;
	fill(k, 1, 1, x, y);
	return 0;
}
  
