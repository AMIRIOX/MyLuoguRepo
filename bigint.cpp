#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 500

template <typename T>
T t_max(T a, T b) {
    return (a > b) ? a : b;
}
struct bigint {
    int len, val[MAXN];
    bigint(int x = 0) {
        // initial struct
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
        while (!val[len]) {
            len--;
        }
    }
    void print() {
        for (int i = t_max(len, 1); i >= 1; i--) {
            printf("%d", val[i]);
        }
    }
    friend std::ostream& operator<<(std::ostream& o, bigint& a) {
        a.print();
        return o;
    }
    friend bigint operator+(bigint a, bigint b) {
        bigint tmp;
        int tlen = t_max(a.len, b.len);
        for (int i = 1; i <= tlen; i++) {
            tmp[i] += a[i] + b[i];
        }
        tmp.flatten(tlen + 1);
        return tmp;
    }
    friend bigint operator*(bigint a, int b) {
        bigint tmp;
        int tlen = a.len;
        for (int i = 1; i <= tlen; i++) {
            tmp[i] = a[i] * b;
        }
        tmp.flatten(tlen + 11);
        return tmp;
    }
};
int main() {
    /* code */
    bigint a(2000000000);
    bigint b(2000000000);
    (a+b).print();
    std::cout << std::endl;
    (a*3).print();
    return 0;
}
