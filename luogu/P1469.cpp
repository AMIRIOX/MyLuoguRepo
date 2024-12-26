#include <cstdio>
int ans,x;
inline int read() {
    int val = 0, flg = 1;
    char ch = (char)getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') flg = 0;
        ch = (char)getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char)getchar();
    }
    return (flg ? val : ~val+1);
}
int main() {
    int n = read();
    while (n--) {
        x = read();
        ans^=x;
    }
    printf("%d",ans);
    return 0;
}