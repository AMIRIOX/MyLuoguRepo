#include <bits/stdc++.h>
using namespace std;
int main() {
    int tmp;
    long long cnt = 0, cnt2 = 0;
    while (scanf("%d", &tmp) != EOF) {
        cnt += tmp;
        cnt2++;
    }
    for (int i = 0; i < cnt2 - 1; i++) cnt *= 2;
    cout << cnt;
    system("pause");
    return 0;
}