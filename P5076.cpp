#include <iostream>
#define MAXN 100010
using namespace std;
struct node {
    int left, right, value, size, num;
    node(int l, int r, int v, int s)
        : left(l), right(r), value(v), size(s), num(1) {}
    node() {}
} t[MAXN];
int cnt;
inline void update(int root) {
    t[root].size = t[t[root].left].size + t[t[root].right].size + t[root].num;
}
int ran(int x, int root) {
    if (root) {
        if (x < t[root].value) return ran(x, t[root].left);
        if (x > t[root].value)
            return ran(x, t[root].right) + t[t[root].left].size + t[root].num;
        return t[t[root].left].size + t[root].num;
    }
    return 1;
}
int kth(int x, int root) {
    if (x <= t[t[root].left].size) return kth(x, t[root].left);
    if (x <= t[t[root].left].size + t[root].num) return t[root].value;
    return kth(x - t[t[root].left].size - t[root].num, t[root].right);
}
// TODO: void insert(int x,int& root);
void insert(int x, int& root) {
    if (x < t[root].value) {
        if (t[root].left) {
            insert(x, t[root].left);
        } else {
            t[t[root].left = ++cnt] = node(0, 0, x, 1);
        }
    } else if (x > t[root].value) {
        if (t[root].right) {
            insert(x, t[root].right);
        } else {
            t[t[root].right = ++cnt] = node(0, 0, x, 1);
        }
    } else
        t[root].num++;
    update(root);
}
int main(/*int argc, const char** argv*/) {
    int opt = 0, n = 0, root = 0, x = 0;
    cin >> n;
    t[root = ++cnt] = node(0, 0, 0x7fffffff, 1);
    while (n--) {
        cin >> opt >> x;
        if (opt == 1) {
            cout << ran(x,root) << endl;;
        } else if (opt == 2) {
            cout << kth(x,root) << endl;
        } else if (opt == 3) {
            cout << kth(ran(x,root)-1,root) << endl;
        } else if (opt == 4) {
            cout << kth(ran(x+1,root),root) << endl;
        } else {
            insert(x,root);
        }
    }
    return 0;
}