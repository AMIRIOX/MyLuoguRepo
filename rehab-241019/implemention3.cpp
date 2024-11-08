#include <iostream>
using namespace std;

const int maxn = 1000;
struct vec{
    int x1;
    int y1;
    int x2;
    int y2;

    vec(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0)
        : x1(0), y1(0), x2(_x2 - _x1), y2(_y2 - _y1) {}

    friend vec operator+(const vec &a, const vec &b) {
        return vec(0, 0, a.x2 + b.x2, a.y2 + b.y2);
    }
}v[maxn];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t1, t2, t3, t4; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t1 >> t2 >> t3 >> t4;
        v[i] = vec(t1, t2, t3, t4);
    }

    cin >> t1 >> t2 >> t3 >> t4;
    vec dest(t1, t2, t3, t4);

    auto cmp = [&](const vec &a, const vec &b) -> bool {
        vec sum = a + b;
        if(sum.x2 * dest.y2 - dest.x2 * sum.y2 == 0) return true;
        else return false;
    };

    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(cmp(v[i], v[j])) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
