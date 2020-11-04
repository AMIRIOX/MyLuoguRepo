#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6+1;
struct node{
    int val;
    int start,end;
    int mark;
    bool isinit;
    node():val(0),start(0),end(0),mark(0),isinit(true) {}
    node(int s, int e) : start(s), end(e), isinit(false) {}
    void addMark(int v) {
        this->mark+=v;
    }
    void clearMark() {
        this->mark=0;
    }
}tree[maxn];
int build(int index, int s, int t) {
    node& cur = tree[index];
    cur=node(s,t);
    int mid = (s+t)/2;
    build(index*2,s,mid);
    build(index*2+1, mid+1,t);
}
signed main() {

    return 0;
}