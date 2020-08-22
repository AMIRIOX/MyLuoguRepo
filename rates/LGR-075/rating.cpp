#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100010;
int a, b, c;
int main() {
    cin >> a >> b >> c;
    if (a < b) {
        while (a != b && c > 0) a++, c--;
    } else {
        while (a != b && c > 0) b++, c--;
    }
    while (c >= 2) {
        c -= 2;
        a++, b++;
    }
    int lowCount = 0;
    while (a >= lowCount + 1 && b >= lowCount + 1) {
        lowCount++;
        a-=lowCount; b-=lowCount;
    }
    cout << lowCount << endl;
    return 0;
}