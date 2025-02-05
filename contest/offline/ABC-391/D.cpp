#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> X_vals;
    map<int, vector<pair<int, int>>> G;
    vector<int> ans(MAX_N, -1);
    vector<int> toline(N + 1, -1);

    vector<pair<int, int>> blocks(N);
    for (int i = 0; i < N; ++i) {
        cin >> blocks[i].first >> blocks[i].second;
        blocks[i].first--;
        // blocks[i].second--;
        X_vals.push_back(blocks[i].first);
    }
    sort(X_vals.begin(), X_vals.end());
    X_vals.erase(unique(X_vals.begin(), X_vals.end()), X_vals.end());

    for (int i = 0; i < N; ++i) {
        int Xi = lower_bound(X_vals.begin(), X_vals.end(), blocks[i].first) - X_vals.begin();
        G[Xi].emplace_back(blocks[i].second, i + 1);
    }

    for (auto &p : G) {
        sort(p.second.begin(), p.second.end());
    }

    int min_line = int(X_vals.size()) == W ? MAX_N : -1;
    for (auto &p : G) {
        min_line = min(min_line, (int)p.second.size());
    }

    // map<int, int> lst;

    /*
    for (auto &p : G) {
        // lst[p.first] = p.second[0].first;
        ans[0] = max(ans[0], p.second[0].first);
        toline[p.second[0].second] = 0;
    }
    */

#ifdef DEBUG
    for (auto &p : G) {
        cout << "for col " << p.first + 1 << ": \n";
        int cnt = 0;
        for (auto &q : p.second) {
            cout << ++cnt << "'s Yi = " << q.first + 1 << " with block id " << q.second << '\n';
        }
    }
#endif

    for (int line = 0; line < min_line; ++line) {
        // int Bz = 0;
        for (auto &p : G) {
            // int Xi = p.first;
            int Yi = p.second[line].first;
            ans[line] = max(ans[line], Yi);
            // Bz = max(Bz, ans[line - 1] + (Yi - lst[Xi]) - 1);
            // lst[Xi] = Yi;
            toline[p.second[line].second] = line;
        }
        ans[line] = max(ans[line], ans[line - 1] + 1);
    }

    int q;
    cin >> q;
    while (q--) {
        int qTi, qAi;
        cin >> qTi >> qAi;
        if (toline[qAi] != -1) {
            cout << (qTi < ans[toline[qAi]] ? "Yes" : "No") << "\n";
        } else {
            cout << "Yes" << '\n';
        }
    }

    return 0;
}


