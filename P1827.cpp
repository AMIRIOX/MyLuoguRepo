#include <iostream>
using namespace std;
char a[100010], b[100010];
void build(int l1, int r1, int l2, int r2) {
    for (int i = l2; i <= r2; i++) {
        if (b[i] == a[l1]) {
            build(l1 + 1, l1 + i - l2, l2, i - 1);
            build(l1 + i - l2 + 1, r1, i + 1, r2);
            cout << a[l1]; // << " ";
            return;
        }
    }
}
int main() {
    string as;
    string bs;
    cin >> as >> bs;
    for (int i = 1; i <= as.size(); i++)
        if (as[i-1] != '\n') b[i] = as[i-1];
    for (int i = 1; i <= bs.size(); i++)
        if (bs[i-1] != '\n') a[i] = bs[i-1];
    build(0,as.size(),0,bs.size());
    return 0;
}