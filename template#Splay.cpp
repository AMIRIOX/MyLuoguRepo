#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;

// Splay
// rotate-splay(), maintain(), get(), clear()
// insert(), delete(), kth(), rk(), pre(), nxt()

int rt, tot;
int ch[maxn][2], fa[maxn], val[maxn], cnt[maxn], sz[i]; 

int get(int x){ return val[x]==ch[x][1]; }
void maintain(int x) { sz[x] = cnt[x] + sz[ch[x][0]] + sz[ch[x][1]]; }
void clear(int x) { val[x] = cnt[x] = sz[x] = ch[x][0] = ch[x][1] = fa[x] = 0; }

// rotate
void rotate(int x) {
    int y=fa[x], z=fa[y], chk=get(x);
    ch[y][chk] = ch[x][chk ^ 1];
    if(ch[x][chk ^ 1]) fa[ch[x][chk^1]] = y;
    ch[x][chk ^ 1] = y;
    fa[y] = x;
    fa[x] = z;
    if(z) ch[z][y==ch[z][1]] = x;
    maintain(y); maintain(x);
    return 0; 
}

// Splay
// 同侧zig-zig旋转由x远及近, 异侧zig-zag旋转由x近及远， 奇偶校验zig时f为根
void splay(int x) {
    for (int f=fa[x]; f=fa[x], f; rotate(x)) {
        if(fa[f]) rotate(get(x) == get(f) ? f : x);
    }
    rt = x;
}

void ins(int k) {
    if(!rt) {
        val[++tot] = k;
        rt = tot; cnt[tot]++;
        maintain(rt);
        return;
    }
    int cur = rt, f = 0;
    while (1) {
        if(val[cur] == k) {
            cnt[cur]++;
            maintain(cur);
            maintain(f);
            splay(cur);
            break;
        }
        f = fa[cur];
        cur=ch[cur][k>val[cur]];
        if(!cur) {
            val[++tot] = k;
            cnt[tot]++;
            fa[tot] = f;
            ch[f][k > val[f]] = tot;
            maintain(tot);
            maintain(f);
            splay(tot);
            break;
        }
    }
}
void del() {}
int pre() {}
int nxt() {}
int kth() {}
int rk() {}


signed main() {

    return 0;
}

