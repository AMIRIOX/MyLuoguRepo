#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    long long n,a,x,y;
    scanf("%lld %lld %lld %lld", &n, &a, &x, &y);
    if(n>a) printf("%lld\n", x*a+y*(n-a));
    else printf("%lld\n",n*x);
    return 0;
}