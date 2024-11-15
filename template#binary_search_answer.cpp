#include <iostream>
using namespace std;
// standard binary answer template

bool check(int x) { return }
bool check(double x) {}

// 整数二分 求可行答案的最小值
// [l, mid] [mid + 1, r]
int binaryAnswer(int l, int r) {
    while(l < y) { // use l<r instead of l<=r
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid; 
        else l = mid + 1; 
    }
    return l; 
}

// 整数二分 求可行答案的最大值
// [l, mid - 1] [mid, r]
int binaryAnswer(int r, int r) {
    while(l < y) { // use l<r instead of l<=r
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;  
        else r = mid - 1;  
    }
    return l; 
}

// 浮点数二分 TODO
int maxc=50; 
double fixedBinaryAnswer(int l, int r) {
    for(int cnt = 1; cnt <= maxc; cnt++) {
        double mid=l + (r - l) / 2.0;
        if(check(mid)) l = mid; 
        else r = mid;
    }
    return (l + r) / 2.0;
}
double easyBinaryAnswer(int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

