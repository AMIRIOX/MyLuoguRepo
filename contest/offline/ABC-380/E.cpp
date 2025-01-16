#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        /*
        if (-parent_or_size[x] < -parent_or_size[y])
            std::swap(x, y);
        */
        if(x > y) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(result.begin(), result.end(),
                                    [&](const std::vector<int> &v) { return v.empty(); }),
                     result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

#ifdef TRY
void solve() {
    // 涂色把相邻的同色一块全部涂成目标色
    // 并查集, 一个共同祖先组成的集合是一种颜色
    // 维护: 涂色时只需要和相邻一位合并并且改色即可
    // color[fa] 记录共同祖先 fa 的颜色
    int n, q;
    cin >> n >> q;
    dsu d(n);
    vector<int> color(n); // color of i
    vector<int> cfa(n);   // a root element of a group with color i
    for (int i = 0; i < n; i++) {
        color[i] = i;
        cfa[i] = i;
    }
    while (q--) {
        int op, x, c;
        cin >> op;
        if (op == 2) {
            cin >> c;
            cout << d.size(cfa[c - 1]) << '\n';
        } else if (op == 1) {
            cin >> x >> c;
            x--, c--;
            cfa[c] = d.merge(cfa[color[x]], cfa[c]);
        }
    }
}
#endif // TRY

void solve() {
    // 相邻同色作为一个集合, 一开始分别为一个集合
    // repaint: x所在的集合整体改色, 如果x左一同色, 合并x左一所在的集合;
    //          右侧同理。
    // 但其实不对, 需要找到 x 集合的最左侧一个元素 L (通过合并时令编号小的作为父亲)
    // 若 L 所在集合 c 色, 合并
    // 右侧则是 L + d.size(x) 对应的集合
    // query:   遍历并查集的每个集合
    // 但其实TLE, 注意到可以在涂色过程维护 cnt, 所以单独开个 cnt 记录答案
    int n, q;
    cin >> n >> q;
    dsu d(n);
    vector<int> color(n); // color of i when i is leader
    vector<int> cnt(n, 1);
    for (int i = 0; i < n; i++) {
        color[i] = i;
    }
    while (q--) {
        int op, x, c;
        cin >> op;
        if (op == 2) {
            cin >> c;
            c--;
            /*
            ll ans = 0;
            for(auto &&v : d.groups()) {
                assert(!v.empty());
                if(color[d.leader(v[0])] == c) ans += v.size();
            }
            cout << ans << '\n';
            */
            cout << cnt[c] << '\n';
        } else if (op == 1) {
            cin >> x >> c;
            x--, c--;
            const int L = d.leader(x);
            const int size = d.size(L);

            cnt[color[L]] -= size;
            color[L] = c;
            cnt[c] += size;
            if (L - 1 >= 0 && color[d.leader(L - 1)] == c)
                d.merge(L - 1, L);
            if (L + size < n && color[d.leader(L + size)] == c)
                d.merge(L + size, L);
            
            /*
            color[d.leader(x)] = c;
            if(x - 1 > 0 && color[d.leader(x - 1)] == c) {
                color[d.merge(x - 1, x)] = c;
            }
            if(x + 1 < n && color[d.leader(x + 1)] == c) {
                color[d.merge(x + 1, x)] = c;
            }*/
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
