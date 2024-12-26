#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6+10;
int heap[maxn];
int n;
void up(int x) {
    while (x > 1 && heap[x] < heap[x / 2]) {
        swap(heap[x], heap[x / 2]);
        x /= 2;
    }
}
void downow(int x) {
    while (x * 2 <= n) {
        int t = x * 2;
        if (t + 1 <= n && heap[t] > heap[t + 1])
            t++;
        if (heap[x] < heap[t])
            break;
        swap(heap[x], heap[t]);
        x = t;
    }
}
void downmy(int x) {
    while ((x * 2 <= n && heap[x] > heap[x * 2]) ||
           (x * 2 + 1 <= n && heap[x] > heap[x * 2 + 1])) {
        if (heap[x * 2 + 1] < heap[x * 2]) {
            swap(heap[x], heap[x * 2 + 1]);
            x = x * 2 + 1;
        } else {
            swap(heap[x], heap[x * 2]);
            x *= 2;
        }
    }
}
void push(int v) {
    heap[++n] = v;
    up(n);
}
int pop() {
    int ret = heap[1];
    heap[1] = heap[n];
    n--;
    downmy(1);
    return ret;
}
int main() {
    int ns;
    cin >> ns;
    for (int i = 0; i < ns; i++) {
        int cmd, num;
        cin >> cmd;
        if (cmd == 1) {
            cin >> num;
            push(num);
        }
        if (cmd == 2)
            cout << heap[1] << endl;
        if (cmd == 3)
            pop();
    }
    return 0;
}