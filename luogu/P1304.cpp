#include <bits/stdc++.h>
using namespace std;
bool isp(int num) {
    if (num == 1) return false;
    if (num <= 2) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void process(int n) {
    for (int i = 2; i < n; i++) {
        if (i != 2 && i % 2 == 0) continue;
        if (isp(i) && (n - i > 0 && isp(n - i))) {
            printf("%d=%d+%d\n",n,i,n-i);
            break;
        }
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=4;i<=n;i+=2){
        process(i);
    }
    system("pause");
    return 0;
}