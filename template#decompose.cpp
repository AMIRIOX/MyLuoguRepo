#include <cstdio>
#include <iostream>
#define re register
using namespace std;
const int maxn = 100010;
int arr[maxn];
int decompose(int x, int a[]) {
    int cnt = 0;
    for (int i = 2; i <= x / i; i++) {
        for (; x % i == 0; x /= i) {
            a[++cnt] = i;
        }
    }
    if (x > 1) a[++cnt] = x;
    return cnt;
}
int main() { 
    int ans = decompose(49,arr);
    cout << ans << endl;
    for(int i=1;i<=ans;i++) {
        cout << arr[i] << ' ';
    }
    return 0; }