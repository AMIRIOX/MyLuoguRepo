#include <bits/stdc++.h>
using namespace std;

struct dsu {
  private:
    int n;
    // root: -1 * component size
    // or:   parent
    vector<int> parent_or_size;

  public:
    vector<vector<int>> member;
    dsu() : n(0), member(0) {}
    explicit dsu(int _n) : n(_n), parent_or_size(n, -1), member(n) {
        for(int i = 0; i < n; i++) member[i].push_back(i);
    }

    int leader(int x) {
        if (parent_or_size[x] < 0)
            return x;
        return parent_or_size[x] = leader(parent_or_size[x]);
    }

    int merge(int x, int y) {
        if ((x = leader(x)) == (y = leader(y)))
            return x;

        // 0: if make less node be the parent
        // if(x > y) swap(x, y);

        // 1: always let small sets merge into large sets
        if (-parent_or_size[x] < -parent_or_size[y])
            swap(x, y);

        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;

        // add: maintain member[x] correct
        member[x].insert(member[x].end(), member[y].begin(), member[y].end());
        sort(member[x].begin(), member[x].end(), greater<int>());
        if (member[x].size() > 10)
            member[x].resize(10);
        return x;
    }

    bool same(int x, int y) { return leader(x) == leader(y); }
    int size(int x) { return -parent_or_size[leader(x)]; }

    vector<vector<int>> groups() {
        vector<int> leader_buf(n), group_size(n, 0);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }

        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(remove_if(result.begin(), result.end(),
                               [&](const vector<int> &v) { return !v.empty(); }),
                     result.end());
        return result;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    dsu d(n);
    while (q--) {
        short op = 0;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            d.merge(u, v);
        } else if (op == 2) {
            int u, k;
            cin >> u >> k;
            u--;
            int fa = d.leader(u);
            if ((int)d.member[fa].size() < k)
                cout << -1 << '\n';
            else
                cout << d.member[fa][k - 1] + 1 << '\n';
        }
    }
    return 0;
}
