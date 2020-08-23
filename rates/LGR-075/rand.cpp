#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;
const int maxn = 100010;

int main() {
    srand((unsigned)time(0));
    long long a = rand() % 10000000;
    long long b = rand() % 10000000;
    long long c = rand() % 10000000;
    cout << a << " " << b << " " << c << endl;
    return 0;
}