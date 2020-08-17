#include <bits/stdc++.h>
using namespace std;
#define maxn 500

struct bigint {
    int len, val[maxn];
    bigint(int x = 0) {
        memset(val, 0, sizeof val);
        for (len = 1; x; len++) {
            val[len] = x % 10, x /= 10;
        }
        len--;
    }
    int& operator[](int i) { return val[i]; }
    void flatten(int L) {
        len = L;
        for (int i = 1; i <= len; i++) {
            val[i + 1] += val[i] / 10, val[i] %= 10;
        }
        while (!val[len]) len--;
    }
    friend bigint operator+(bigint a, bigint b) {
        bigint tmp;
        int tlen = max(a.len, b.len);
        for (int i = 1; i <= tlen; i++) {
            tmp[i] += a[i] + b[i];
        }
        tmp.flatten(tlen + 1);
        return tmp;
    }
    friend bigint operator*(bigint a, int c) {
        bigint tmp;
        int tlen = a.len;
        for (int i = 1; i <= tlen; i++) {
            tmp[i] = a[i] * c;
        }
        tmp.flatten(tlen + 11);
        return tmp;
    }
    void print() {
        for(int i=max(len,1);i>=1;i--) {
            cout << val[i];
        }
    }
};
int main() {
    /* code */
    bigint a(2000000000);
    bigint b(2000000000);
    (a + b).print();
    std::cout << std::endl;
    (a * 3).print();
    return 0;
}
