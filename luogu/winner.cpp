#include <iostream>
#define MAXN 100010
using namespace std;
int value[MAXN], winner[MAXN / 2];
int n;
void dfs(int x) {
    // if(x==1 || x==2 || x==3) cout << x << endl;
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
            winner[x] = winner[2 * x + 1];
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        cin >> value[i + (1 << n)];
        winner[i + (1 << n)] = i + 1;
    }
    dfs(1);
    cout << ((value[2] > value[3]) ? winner[3] : winner[2]);
    return 0;
}