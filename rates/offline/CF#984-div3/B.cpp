#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int maxn = 2e5 + 10;

// fuck

/*
struct brand {
    vector<int> bots;
    int brand_max;
    int brand_id;
    brand(int c1 = 0, int id = 0) {
        brand_max = c1;
        bots.push_back(c1);
        brand_id = id;
    }
    bool operator<(const brand& o) {
        return this->brand_max > o.brand_max;
    }
};

int cnt[maxn];
void solve() {
    memset(cnt, 0, sizeof cnt);
    int n, k;
    cin >> n >> k;
    int maxc = 0, bs = 0;
    vector<brand> v;
    for(int i = 1; i <= k; i++) {
        int tb, tc;
        cin >> tb >> tc;
        if(!cnt[tb]) {
            v.push_back(brand(tc, tb));
            bs++;
            cnt[tb] = 1;
        }else for(int j = 0; j < v.size(); j++) {
            if(v[j].brand_id == tb) {
                v[j].brand_max += tc;
                v[j].bots.push_back(tc);
                break;
            }
        }
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    int tmp = n;
    for(int i = 0; i < min(n, bs); i++) {
        if(!tmp) break;
        ans += accumulate(v[i].bots.begin(), v[i].bots.end(), 0);
        tmp--;
    }
    cout << ans << endl;
}
*/

int a[maxn];
void solve() {
    int n, k;
    memset(a, 0, sizeof a);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++) {
        int tb, tc;
        scanf("%d %d", &tb, &tc);
        a[tb] += tc;
    } 
    sort(a + 1, a + k + 1, greater<int>());
    int tmp = n;

    long long ans = 0;
    for(int i = 1; i <= min(n, k); i++) {
        ans += a[i];
    }
    cout << ans << endl;
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
