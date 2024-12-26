#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int maxn=1e6+50;
int a[maxn];
int n, ans;
bool vis[maxn];
/*struct pqwq{
    priority_queue<int> qa, qd;
    void push(int v) {
        qa.push(v);
    }
    void erase(int v){
        qd.push(v);
    }
    int top() {
        while(!qd.empty() && qd.top()==qa.top())  {qa.pop();qd.pop();}
        return qa.empty()?0:top();
    }
}q;*/
priority_queue<int> q;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        int t;
        scanf("%d", &t);
        a[i]=t;
        q.push(t);
    }
    int ind=0;
    while(!q.empty()) {
        ind++;
        if(ind>n) ind=1, ans++;
        if(a[ind]==q.top() && !vis[ind]) {
            // cout << a[ind] << "is the biggest." << endl;
            q.pop();
            vis[ind]=true;
        }
        if(ind<n && q.empty()) ans++;
    }
    printf("%d", ans);
    return 0;
}