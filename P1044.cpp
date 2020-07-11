// #include <bits/stdc++.h>
// using namespace std;
// int f[1001];
// int main() {
//     int n;
//     cin >> n;
//     f[0]=f[1]=1;
//     for(int i=2;i<=n;i++){
//         for(int j=0;j<i;j++){
//             f[i]+=f[j]*f[i-j-1];
//         }
//     }
//     cout << f[n];
//     system("pause");
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
long long arr[10001][10001];
long long dfs(int q,int s){
    if(arr[q][s]) return arr[q][s];
    if(q==0) return 1;
    if(s>0) arr[q][s]+=dfs(q,s-1);
    arr[q][s]+=dfs(q-1,s+1);
    return arr[q][s];
}
int main(){
    int n;
    cin >> n;
    long long ans = dfs(n,0);
    cout << ans;
    system("pause");
    return 0;
}