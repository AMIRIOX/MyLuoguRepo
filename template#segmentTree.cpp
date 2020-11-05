/*
* Segment Tree: The art of interval query and modification.
* Author = amiriox lmy
* Time = { 2020-11-05, 7:35 }
? >OK struct node: 线段树节点, 表示一个区间
? >OK func build: 构造一棵线段树
? >OK func pushDown: 延迟更新懒标记
? >OK func query: 根据相关条件(符合结合律)查询
?  | 在P3372, P3373中为求和,
?  | P6242中为极值
? >OK func updateOne: 单点更新
? >OK func updateInterval: 区间更新
*/

#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL

#define LEFT (index << 1)
#define RIGHT (index << 1) + 1

using namespace std;
const int maxn = 1e6 + 1;
int bas[maxn], n, m, x, y, k, opt;
struct node {
    int val;
    int start, end;
    int mark;
    // node() : val(0), start(0), end(0), mark(0) {}
    // node(int s, int e) : start(s), end(e) {}
    node(int s = 0, int e = 0) {
        start = s, end = e;
        val = mark = 0;
    }
    void addMark(int v) { this->mark += v; }
    void clearMark() { this->mark = 0; }
} tree[maxn];
void pushDown(int index) {
    node& cur = tree[index];
    if (cur.mark) {
        tree[LEFT].val += cur.mark;
        tree[RIGHT].val += cur.mark;
        tree[LEFT].addMark(cur.mark);
        tree[RIGHT].addMark(cur.mark);
        cur.clearMark();
    }
}
void build(int index, int s, int t) {
    node& cur = tree[index];
    cur = node(s, t);
    if (s == t) {
        cur.val = bas[s];
        return;
    }
    int mid = (s + t) >> 1;
    build(LEFT, s, mid);
    build(RIGHT, mid + 1, t);
    // cur.val = min(tree[LEFT].val, tree[RIGHT].val);
    cur.val = tree[LEFT].val + tree[RIGHT].val;
}

int query(int index, int s, int t) {
    node& cur = tree[index];
    //*       cs    ce
    //*    S             T
    if (cur.end < s || cur.start > t) {
        // cout << cur.end << " " << s << " " << cur.start << " " << t << endl;
        return 0;  // INF
    }
    if (cur.start >= s && cur.end <= t) return cur.val;
    pushDown(index);
    // return min(query(LEFT, s, t), query(RIGHT, s, t));
    return query(LEFT, s, t) + query(RIGHT, s, t);
}

void updateOne(int index, int needup, int inc) {
    node& cur = tree[index];
    if ((cur.start == cur.end) && (cur.start == needup)) {
        cur.val += inc;
        cur.addMark(inc);
        return;
    }
    int mid = (cur.start + cur.end) >> 1;
    if (needup <= mid)
        updateOne(LEFT, needup, inc);
    else
        updateOne(RIGHT, needup, inc);
    // cur.val = min(tree[RIGHT].val, tree[LEFT].val);
    cur.val = tree[RIGHT].val + tree[LEFT].val;
}

void update(int index, int s, int t, int inc) {
    node& cur = tree[index];
    if (cur.end < s || cur.start > t) return;
    if (cur.start >= s && cur.end <= t) {
        cur.val += inc;
        cur.addMark(inc);
        return;
    }
    pushDown(index);
    update(LEFT, s, t, inc);
    update(RIGHT, s, t, inc);
    // cur.val = min(tree[LEFT].val, tree[RIGHT].val);
    cur.val = tree[LEFT].val + tree[RIGHT].val;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &bas[i]);
    }
    build(1, 1, n);
    while (m--) {
        scanf("%lld", &opt);
        if (opt == 1) {
            // cin >> x >> y >> k;
            scanf("%lld %lld %lld", &x, &y, &k);
            update(1, x, y, k);
        } else if (opt == 2) {
            // cin >> x >> y;
            scanf("%lld %lld", &x, &y);
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}