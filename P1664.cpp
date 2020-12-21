#include <iostream>
#include <cmath>
using namespace std;
int N, lxl, jl, zero, curinc;
// 总共天数, 连续天数, 亮丽, 漏打天数, 当前加的奖励
bool zerod = false;
int a;
int gh(int n) {
    return pow(2,n-1);
}
void updateCurinc() {
    /*
    1 天：奖励 1（千里之行，始于足下）

    3 天：奖励 2（坚持 3 天了，加油！）

    7 天：奖励 3（曜日轮回）

    30 天：奖励 4（月圆月缺，习惯养成）

    120 天：奖励 5（坚持四个月了！）

    365 天：奖励 6（一年四季都坚持下来了！真不容易！）
    */
    if(lxl>=1 && lxl<3) {
        curinc = 1;
    }else if(lxl>=3 && lxl<7) {
        curinc = 2;
    }else if(lxl>=7 && lxl<30) {
        curinc = 3;
    }else if(lxl>=30 && lxl<120) {
        curinc = 4;
    }else if(lxl>=120 && lxl<365) {
        curinc = 5;
    }else if(lxl >=365) {
        curinc = 6;
    }
}
int main() {
    cin >> N;
    for(int i=1; i<=N ;i++) {
        cin >> a;
        if(a) {
            if(zerod) {
                lxl -= gh(zero);
                zero = 0;
                zerod = false;
                if(lxl<0) lxl=0;
            }
            lxl++;
            updateCurinc();
            jl+=curinc;
        }else {
            zerod = true;
            zero++;
        }
    }
    cout << jl;
    return 0;
}
