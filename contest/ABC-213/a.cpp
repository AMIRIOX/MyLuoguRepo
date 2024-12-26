#include <iostream>
#include <cstdio>
using namespace std;
int A,B;
signed main() {
    scanf("%d %d", &A, &B);
    // printf("%d %d\n",A,B);
    for(int i=0;i<=255;i++) {
        if((A^i)==B) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}