#include <iostream>
using namespace std;
int qp1(int a, int n) {
    if(n == 0) return 1;
    else if(n & 1) return qp1(a, n - 1) * a;
    else{
        int tmp = qp1(a, n / 2);
        return tmp * tmp;
    }
}
int qp2(int a, int n) {
    int ans = 1;
    while(n) {
        if(n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
int main() {
    int a, n;
    cin >> a >> n;
    cout << qp1(a, n) << " " << qp2(a, n) << endl;
}
