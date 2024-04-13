#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;

// Splay
// rotate-splay(), maintain(), get(), clear()
// insert(), delete(), kth(), rk(), pre(), nxt()

int rt, tot;
int ch[maxn][2], fa[maxn], val[maxn], cnt[maxn], sz[maxn]; 

int get(int x){ return x == ch[fa[x]][1]; } // remember not "val[x]"
void maintain(int x) { sz[x] = cnt[x] + sz[ch[x][0]] + sz[ch[x][1]]; }
void clear(int x) { val[x] = cnt[x] = sz[x] = ch[x][0] = ch[x][1] = fa[x] = 0; }

// rotate
void rotate(int x) {
    int y = fa[x], z = fa[y], chk = get(x);
    ch[y][chk] = ch[x][chk ^ 1];
    if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
    ch[x][chk ^ 1] = y;
    fa[y] = x;
    fa[x] = z;
    if(z) ch[z][y == ch[z][1]] = x;
    maintain(y); maintain(x);
    return; 
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
        f = cur;  // not fa[cur]. (cur -> ch[cur..] <=> f(cur)->fa[cur]
        cur = ch[cur][k>val[cur]];
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
int pre() {
    // 小于x的节点里最大的，这里x是rt
    int cur = ch[rt][0];
    if(!cur) return cur;
    while(ch[cur][1]) cur = ch[cur][1];
    splay(cur);
    return cur;
}
int nxt() {
    int cur = ch[rt][1];
    if(!cur) return cur;
    while(ch[cur][0]) cur = ch[cur][0];
    splay(cur);
    return cur;
}
int kth(int k) {
    // 查询排名为k的数，返回类型为val
    // 要检查的是sz
    int cur = rt;
    while(1) {
        if(ch[cur][0] && k <= sz[ch[cur][0]]) {
            cur = ch[cur][0];
        }else {
            k -= cnt[cur] + sz[ch[cur][0]];
            if(k <= 0) {
              splay(cur);
              return val[cur];
            }
            cur = ch[cur][1];
        }
    }
}
int rk(int k) {
    // 查询k这个val的排名，返回类型为排名res
    int cur = rt, res = 0;
    while(1) {
        if(k < val[cur]){
            cur = ch[cur][0];
        }else {
            res += sz[ch[cur][0]];
            if(val[cur] == k || !cur) {
                if(cur) splay(cur);
                return res + 1;
            }
            res += cnt[cur];
            cur = ch[cur][1];
        }
    }
}

void del(int k) {
    rk(k);   // Splay rotate k(x) to root
    if(cnt[rt] > 1) {
        cnt[rt]--;
        maintain(rt);
        return;
    }
    if(!ch[rt][0] && !ch[rt][1]) {
        clear(rt);
        rt = 0;
        return; 
    }
    if(!ch[rt][0]) {
        int cur = rt;
        rt = ch[rt][1];
        fa[rt] = 0;
        clear(cur);
        return;
    }
    if(!ch[rt][1]) {
        int cur = rt;
        rt = ch[rt][0];
        fa[rt] = 0;
        clear(cur);
        return;
    }
    int cur = rt, x = pre();  // rt左子树最大值x，准备合并
    fa[ch[cur][1]] = x;
    ch[x][1] = ch[cur][1];
    clear(cur);
    maintain(rt);
}
int n, opt, x;
inline void dbg(int x) { cout << x << endl; }
signed main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &opt, &x);
        if(opt == 1) {
            ins(x);
        }else if(opt == 2) {
            del(x);
        }else if(opt == 3) {
            cout << rk(x) << endl;
        }else if(opt == 4) {
            cout << kth(x) << endl;
        }else if(opt == 5) {
            ins(x); cout << val[pre()] << endl; del(x);
        }else if(opt == 6) {
            ins(x); cout << val[nxt()] << endl; del(x);
        }
    }
    return 0;
}

