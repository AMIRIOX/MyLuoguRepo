#include <iostream>
#include <cstdio>
#include <cmath>
int n;
int main() {
    std::cin >> n;
    bool ok = false;
    for(int f=sqrt(2*n+1); f>=2; f--) {
        if(2*n%f) continue;
        int x1=2*n/f-f+1;
        if(x1%2==0) {
            ok=true;
            std::cout << x1/2 << std::endl;
        }
    }
    if(!ok) std::cout << "No Solution" << std::endl;
    return 0;
}