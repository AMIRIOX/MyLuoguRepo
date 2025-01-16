#include <bits/stdc++.h>
using namespace std;

// begin

struct dsu {
  public:
    dsu() : n(0) {}
    explicit dsu(int _n) : n(_n), parent_or_size(n, -1) {}

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

  private:
    int n;
    // root: -1 * component size
    // or:   parent
    vector<int> parent_or_size;
};

// end
