#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6 + 10;

int n, Q, tot;
int tree[maxn][2];
int flg[maxn], val[maxn], ans[maxn];
char op[maxn];
bool diff[maxn];
// 以1~n为叶子节点
// 栈里放的是树

string get_next(istream& input) {
    string ret;
    if(input >> ret) return ret;
    return "";
}

inline int get_num(const string& s) {
    return atoi(s.substr(1).c_str());
}

int dfs_ans(int root) {
    if(!tree[root][0] && !tree[root][1]) 
        return ans[root] = flg[root] ^ val[root];
    if(op[root] == '&')
        return ans[root] = flg[root] ^ (dfs_ans(tree[root][0]) & dfs_ans(tree[root][1]));
    else if(op[root] == '|')
        return ans[root] = flg[root] ^ (dfs_ans(tree[root][0]) | dfs_ans(tree[root][1]));
    else return -1;
}

void dfs_diff(int root) {
    if(!tree[root][0] && !tree[root][1]) {
        diff[root] = true;
        return;
    }
    if(op[root] == '|') {
        if(ans[tree[root][0]] == 0 && ans[tree[root][1]] == 0) {
            dfs_diff(tree[root][0]);
            dfs_diff(tree[root][1]);
        }
        if(ans[tree[root][0]] == 1 && ans[tree[root][1]] == 0) {
            dfs_diff(tree[root][0]);
        }else if(ans[tree[root][0]] == 0 && ans[tree[root][1]] == 1) {
            dfs_diff(tree[root][1]);
        }
    }else if(op[root] == '&') {
        if(ans[tree[root][0]] == 1 && ans[tree[root][1]] == 1) {
            dfs_diff(tree[root][0]);
            dfs_diff(tree[root][1]);
        }
        if(ans[tree[root][0]] == 1 && ans[tree[root][1]] == 0) {
            dfs_diff(tree[root][1]);
        }else if(ans[tree[root][0]] == 0 && ans[tree[root][1]] == 1) {
            dfs_diff(tree[root][0]);
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    string str, cur;
    getline(cin, str);
    istringstream input(str);
    cin >> n; tot = n;

    stack<int> s;
    while(!(cur = get_next(input)).empty()) {
        if(cur == "!") {
            flg[s.top()] ^= 1;
        }else if(cur.size() == 1) {
            int left = s.top(); s.pop();
            int right = s.top(); s.pop();
            s.push(++tot);
            op[tot] = cur[0];
            tree[tot][0] = left;
            tree[tot][1] = right;
        }else {
            s.push(get_num(cur));
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        if(v) val[i] = true;
        else val[i] = false;
    }
    dfs_ans(tot);
    dfs_diff(tot);
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int q; cin >> q;
        if(diff[q]) cout << !ans[tot] << '\n';
        else cout << ans[tot] << '\n';
    }
    return 0;
}
