#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int> > small;
priority_queue<int, vector<int>, less<int> > big;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (!big.empty() && x <= big.top()) {
            big.push(x);
        } else {
            small.push(x);
        }
        if (small.size() < (small.size() + big.size() + 1) / 2) {
            small.push(big.top());
            big.pop();
        } else if (small.size() > (small.size() + big.size() + 1) / 2) {
            big.push(small.top());
            small.pop();
        }
        if (i % 2) {
            printf("%d\n", small.top());
        }
    }
    return 0;
}