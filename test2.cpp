#include <cstdio>
#include <iostream>
using namespace std;
// 第一天+1 接下来两天+2 接下来三天+3
// 1*1 + 2*2 + 3*3 +
// n天时tot=？
int n, cur = 1, tot = 0;
int main() {
    scanf("%d", &n);
    while (n >= cur) {
        tot += (cur * cur);
        n -= cur;
        cur++;
    }
    if (n != 0)
        tot += cur * n;
    printf("%d\n", tot);
    return 0;
}

// n=1 | 1
// n=2 | 1+2
// n=3 | 1+2+2
// n=4 | 1+2+2+3
// n=5 | 1+2+2+3+3
// n=6 | 1+2+2+3+3+3
// n=7 | 1+2+2+3+3+3+4