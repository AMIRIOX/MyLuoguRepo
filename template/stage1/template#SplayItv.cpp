#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int tot, rt;
int val[maxn], sz[maxn], ch[maxn][2], fa[maxn], lazy[maxn];
int n, m, x, y, a[maxn];
// rotate(), splay(), ins(), build()
// get(), maintain(), clear()
// tagrev(), push_down()

int get(int x) { return x == ch[fa[x]][1]; }
void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }

void rotate(int x) {
    int f = fa[x], g = fa[f], chk = get(x);
    ch[f][chk] = ch[x][chk ^ 1];
    if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = f;
    ch[x][chk ^ 1] = f;
    fa[f] = x;
    fa[x] = g;
    if(g) ch[g][f == ch[g][1]] = x;
    maintain(f); maintain(x);
}

void splay(int x, int goal = 0) {
    if(goal == 0) rt = x;
    while(fa[x] != goal) {
        int f = fa[x], g = fa[f];
        if(g != goal) rotate(get(f) == get(x) ? f : x);
        rotate(x);
    }
}

void tagrev(int x) {
    swap(ch[x][0], ch[x][1]);
    lazy[x] ^= 1;
}

void push_down(int x) {
    if(lazy[x]) {
        tagrev(ch[x][0]);
        tagrev(ch[x][1]);
        lazy[x] = 0;
    }
}

int kth(int k) {
    int cur = rt;
    while(1) {
        push_down(cur); //只要用到左右子树信息就要更新标记
        if(ch[cur][0] && k <= sz[ch[cur][0]]) {
            cur = ch[cur][0]; 
        }else {
            k -= 1 + sz[ch[cur][0]];
            if(k <= 0) {   //<=
                splay(cur);
                return cur;
            }
            cur = ch[cur][1];
        }
    }
}

void reverse(int l, int r) {
    int L = kth(l), R = kth(r+2);
    splay(L), splay(R, L);
    tagrev(ch[ch[L][1]][0]);
}

int build(int f, int l, int r) {
    if(l > r) return 0;
    int mid = l+(r-l)/2, cur = ++tot;
    val[cur] = a[mid], fa[cur] = f;
    ch[cur][0] = build(cur, l, mid-1);
    ch[cur][1] = build(cur, mid+1, r);
    maintain(cur);
    return cur;
}

void print(int x) {
    push_down(x);
    if(ch[x][0]) print(ch[x][0]);
    if(val[x]>=1 && val[x]<=n) printf("%d ", val[x]);
    if(ch[x][1]) print(ch[x][1]);
}
signed main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n+1; i++) a[i] = i;
    rt = build(0, 0, n+1);
    while(m--) {
        scanf("%d %d", &x, &y);
        reverse(x, y);
    }
    print(rt);
    return 0;
}
