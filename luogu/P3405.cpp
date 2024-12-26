#include <iostream>
#include <vector>
#define mod 10007
using namespace std;
long long ans;
char a[10010], b[10010];
vector<pair<int, int> > v[mod + 2];
inline int gethash(char A[], char B[]) {
    return (A[0] - 'A') + (A[1] - 'A') * 26 + (B[0] - 'A') * 26 * 26 +
           (B[1] - 'A') * 26 * 26 * 26;
}
inline void insert(int x) {
    int h = x % mod;
    for (int i = 0; i < v[h].size(); i++) {
        if (v[h][i].first == x) {
            v[h][i].second++;
            break;
        }
    }
    v[h].push_back(pair<int, int>(x, 1));
}
inline int findx(int x) {
    int h = x % mod;
    for (int i = 0; i < v[h].size(); i++) {
        if (v[h][i].first == x) return v[h][i].second;
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a[0] != b[0] || a[1] != b[1]) ans += findx(gethash(b, a));
        insert(gethash(a, b));
    }
    cout << ans;
    return 0;
}