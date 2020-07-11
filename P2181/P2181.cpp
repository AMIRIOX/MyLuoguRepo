#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL n;
ULL result;
int main(){
    cin >> n;
    result = n*(n-1)/2*(n-2)/3*(n-3)/4;
    cout << result;
    return 0;
} 
