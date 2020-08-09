#include <iostream>
#define MAXN 260
using namespace std;
int value[MAXN], winner[MAXN / 2];
int n;
void dfs(int x) {
    if (x >= 1 << n) {
        return;
    } else {
        dfs(x * 2);
        dfs(x * 2 + 1);
        int leftChild = value[x * 2];
        int rightChild = value[x * 2 + 1];
        if (leftChild > rightChild) {
            value[x] = leftChild;
            winner[x] = winner[2 * x];
        } else {
            value[x] = rightChild;
            winner[x] = winner[2 * x + !];
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        cin >> value[i + (1 << n)];
        winner[i + (i << n)] = i + 1;
    }
    dfs(1);
    cout << ((winner[2] > winner[3]) ? winner[3] : winner[2]);
    return 0;
}