// !unaccepted WA on #4 test case 283
// 这还调你妈了

// [l, NaN) or (NaN, r]: easy to construct
// l, x, r: 4 conditions to construct
// l, x1, x2, ..., x2n, r: 
    // def f(x)=2*floor(x/2). 
    // x+y=2n; x-y=f(r)/f(l) (x-y>1)
    // if x>0, y>0 easy to construct
// l, x1, x2, ..., x2n+1, r:
// try x1=2l, x1=floor(l/2), x2n+1=2r, x2n+1=floor(r/2)

/*
#include <bits/stdc++.h>
#define test do{ cout<<"here " << t <<endl; }while(0);
using namespace std;
const int maxn = 2e5+10;
int n; int a[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v; // index
        for(int i=1; i<=n; i++) { 
            cin >> a[i]; 
            if(~a[i]) v.push_back(i);
        }
        if(!v.size()) {
            for(int i=1; i<=n; i++) {
                cout << (1<<i) << " ";
            }
            cout << endl;
            continue;
        }
        int flg = 0;
        for(int i=v[0]-1; i>=1; i--) {
            if(!flg) a[i] = a[i+1]*2;
            else a[i] = a[i+1]/2;
            flg = 1 - flg;
        }
        flg = 0;
        for(int i=v[int(v.size())-1]+1; i<=n; i++) {
            if(!flg) a[i] = a[i-1]*2;
            else a[i] = a[i-1]/2;
            flg = 1 - flg;
        }
        int ok = 1;
        for(int i=0; i<int(v.size())-1; i++) {
            // 相邻但不合规
            if(v[i] == v[i+1]-1 && a[v[i]]/2 != a[v[i+1]] && a[v[i]] != a[v[i+1]]/2) { ok=0; break; }
            // 已经合规的两个数
            if(a[v[i]]/2 == a[v[i+1]] || a[v[i]] == a[v[i+1]]/2) {
                // special processing
                if(v[i] == v[i+1]-1) continue;
                // if((v[i+1]-v[i]-1)%2) {ok=0; break;}
                flg = 0;
                for(int j=1; j<=(v[i+1]-v[i]-1); j++) {
                    if(!flg) a[v[i]+j] = a[v[i+1]];
                    else a[v[i]+j] = a[v[i]];
                    flg = 1 - flg;
                }
                continue;
            }
            int vl = a[v[i]], vr = a[v[i+1]];
            int cnt1 = 0, cnt2 = 0;
            while(vl!=1) { 
                cnt1++; vl/=2;
                if((a[v[i]]==1 || a[v[i]]==1) && vl==1) break;
                if(a[v[i]+cnt1]==-1) a[v[i]+cnt1]=vl;
                else if(a[v[i]+cnt1-1]/2 == a[v[i]+cnt1] || a[v[i]+cnt1-1] == a[v[i]+cnt1]/2) { ok = 3; }
                else { ok=0; break;}
            }
            if(ok==3) continue;
            if(!ok) break;
            while(vr!=1) { cnt2++; vr/=2; }
            int mid = cnt1 + cnt2 - 1, rmid = v[i+1]-v[i]-1;
            if(mid > rmid || (rmid-mid)%2) { ok = 0; break; }
            flg = 1;
            if(rmid-mid) {
                for(int j=1; j<=rmid-mid; j++){
                    if(a[v[i]+cnt1-1+j]==-1) a[v[i]+cnt1+j-1] = flg;
                    flg = 3 - flg;
                }
            }
            vr = a[v[i+1]];
            for(int j = 1; j <= cnt2; j++) {
                a[v[i+1]-j] = vr/2;
                vr/=2;
            }
        }
        if(!ok) { cout << "-1" << endl; continue; }
        for(int i=1; i<=n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0; 
}
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n; 
void solve() {
    cin >> n;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    if(*max_element(v.begin(), v.end()) < 0) v[0]=1;
    priority_queue<pair<int, int> > q; // v[i], i
    for(int i=0; i<n; i++) if(~v[i]) q.emplace(v[i], i);
    while(!q.empty()) {
        auto [val, i] = q.top(); q.pop();
        if(i > 0 && v[i-1] == -1) 
            q.emplace(v[i-1] = val==1 ? 2 : val/2, i-1);
        if(i < n-1 && v[i+1] == -1)
            q.emplace(v[i+1] = val==1 ? 2 : val/2, i+1);
    }
    for(int i=1; i<int(v.size()); i++)
        if(v[i]/2!=v[i-1] && v[i]!=v[i-1]/2) 
            v = {-1};
    for(int i: v) cout << i << " ";
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}
