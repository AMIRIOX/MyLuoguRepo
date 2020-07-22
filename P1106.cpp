#include <algorithm>
#include <iostream>
using namespace std;
int a[300], k;
int main() {
    int n;
    for (int i = 0;; ++i) {
        char c = (char)getchar();
        if (c == '\n' || c == '\r' || c == ' ') {
            n = i;
            break;
        } else
            a[i] = c-'0';
    }
    cin >> k;
    sort(a, a + n);
    // cout << n << " ";
    
    for(int i=0;i<n-k;i++) {
        cout << a[i];
    }
    return 0;
}