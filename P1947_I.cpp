#include <iostream>
using namespace std;

extern "C" int Seniorious(int x);

extern "C" int Chtholly(int n, int a) {
    int l=1, r=n;
    // int ans = 1;
    while(l < r) {
        int mid = l+(r-l)/2;
        if(Seniorious(mid)>=0) r=mid;
        else l=mid+1;
    }
    return l;
}
