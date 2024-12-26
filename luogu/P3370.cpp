#include <iostream>
#include <vector>
#define mod 10007
#define base 261
using namespace std;
vector<std::string> v[mod + 2];
char a[100010];
int ans;
void insert() {
    int hash = 1;
    for (int i = 0; a[i]; i++) hash = (hash * 1ll * base + a[i]) % mod;
    string x = a;
    for (int i = 0; i < v[hash].size(); i++) {
        if (v[hash][i] == x) return;
    }
    v[hash].push_back(x);
    ans++;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        insert();
    }
    cout << ans << endl;
    return 0;
}