#include <iostream>
#define P 15
using namespace std;
int n,ans,qo[100],qa[100],qb[100],asw[100];

void dfs(int k) {
    if(k>n) {
        ans++;
        if(ans<=3) {
            for(int i=1;i<=n;i++) {
                cout << asw[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for(int i=1;i<=n;i++) {
        if(qo[i]==0 && qa[k+i]==0 && qb[k-i+P]==0) {
            asw[k]=i;
            qo[i]=1, qa[k+i]=1,qb[k-i+P]=1;
            dfs(k+1);
            qo[i]=0, qa[k+i]=0,qb[k-i+P]=0;
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}