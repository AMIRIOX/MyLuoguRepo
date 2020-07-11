#include <iostream>
#include <cstdio>
using namespace std;
int _three(int n) {
    return n+1;
}
int _two(int n) {
    return _three(n+1);
}
int _one(int n) {
    return _two(n+1);
}
int main(){
    cout << _one(10);
    //system("pause");
    return 0;
}