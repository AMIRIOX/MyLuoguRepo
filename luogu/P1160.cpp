#include <iostream>
#define MAXN 1000005
using namespace std;
struct node {
    int pre, nxt, val;
    node(int pre_ = 0, int nxt_ = 0, int val_ = 0)
        : pre(pre_), nxt(nxt_), val(val_) {}
};
node s[MAXN];
int n, m;
int tot = 0, index[MAXN];  // s[tot+1]
// int find(int x) {
//     int cur = 1;
//     while (cur && s[cur].val != x) cur = s[cur].nxt;
//     return cur;
// }
void insertFront(int x, int val) {
    int cur = index[x];
    s[++tot] = node(s[cur].pre, cur, val);
    s[s[cur].pre].nxt = tot;
    s[cur].pre = tot;
    index[val] = tot;
}
void insertBack(int val, int x) {
    int cur = index[x];
    s[++tot] = node(cur, s[cur].nxt, val);
    s[s[cur].nxt].pre = tot;
    s[cur].nxt = tot;
    index[val] = tot;
}
void del(int x) {
    int cur = index[x];
    int leftNode = s[cur].pre;
    int rightNode = s[cur].nxt;
    s[leftNode].nxt = rightNode;
    s[rightNode].pre = leftNode;
    index[x] = 0;
}
int main() {
    int k,p,x,now;
    cin >> n;
    s[0] = node();
    insertBack(1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> k >> p;
        p ? insertBack(i, k) : insertFront(k, i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (index[x]) del(x);
    }
    now = s[0].nxt;
    while (now) {
        cout << s[now].val << " ";
        now = s[now].nxt; 
    }
    return 0;
}
