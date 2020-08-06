#include <iostream>
#include <queue>
using namespace std;
int N, A, B;
int visited[1000],ks[1000];
struct node {
    int floor;
    int K;
};
queue<node> Q;
int main() {
    cin >> N >> A >> B;
    for(int i=1;i<=N;i++) {
        cin >> ks[i];
    }
    Q.push((node){A,0});
    visited[A]=1;
    node cur;
    while(!Q.empty()) {
        cur = Q.front();
        Q.pop();
        if(cur.floor==B) break;
        for(int sign=-1;sign<=1;sign++) {
            int target = cur.floor+ks[cur.floor]*sign;
            if(target>=1 && target<=N && visited[target]==0) {
                Q.push((node){target,cur.K+1});
                visited[target]=1;
            }
        }
    }
    if(cur.floor==B) cout << cur.K << endl;
    else cout << -1 << endl;
    return 0;
}