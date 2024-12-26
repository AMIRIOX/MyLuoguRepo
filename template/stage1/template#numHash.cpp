#include <iostream>
#include <vector>
#define mod 10007
using namespace std;
vector<int> v[mod + 2];
int ans;
void insert(int x) {
    int meta = x % mod;
    for (int i = 0; i < v[meta].size(); i++) {
        if (v[meta][i] == x) return;
    }
    v[meta].push_back(x);
    ans++;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        insert(c);
    }
    cout << ans << endl;
}