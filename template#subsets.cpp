#include <cstdio>
#include <iostream>
// #define int long long
using namespace std;
const int maxn = 1e5 + 10;

int n, a[maxn], bitvec[maxn];

// 增量构造法
void printSubsetsByIncrease(int cur) {
    for (int i = 0; i < cur; i++) printf("%d ", a[i]);
    printf("\n");
    int s = cur ? a[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++) {
        a[cur] = i;
        printSubsetsByIncrease(cur + 1);
    }
}

// 位向量法
void printSubsetByBitVec(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            if (bitvec[i]) printf("%d ", i);
        }
        printf("\n");
    } else {
        bitvec[cur] = 1;
        printSubsetByBitVec(cur + 1);
        bitvec[cur] = 0;
        printSubsetByBitVec(cur + 1);
    }
}

// 二进制法
void printBinarySet(int S) {
    for (int i = 0; i < n; i++) {
        if (S & (1 << i)) printf("%d ", i);
    }
    printf("\n");
}
void printSubsetByBinary() {
    for (int i = 0; i < (1 << n); i++) {
        printBinarySet(i);
    }
}

signed main() {
    cin >> n;
    printSubsetsByIncrease(0);
    printf("\n---------------------------------\n");
    printSubsetByBitVec(0);
    printf("\n---------------------------------\n");
    printSubsetByBinary();
    return 0;
}