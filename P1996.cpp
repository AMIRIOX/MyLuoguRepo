#include <cstdio>
#include <queue>
using namespace std;
queue<int> child;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++)child.push(i);
    while (child.size() != 1) {
        for(int i=1;i<k;i++) {
            child.push(child.front());
            child.pop();
        }
        printf("%d ",child.front());
        child.pop();
    }
    printf("%d",child.front());
    return 0;
}