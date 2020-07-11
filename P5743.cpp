#include <bits/stdc++.h>
using namespace std;
int peach = 1;
void process() {
    peach++;
    peach *= 2;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        process();
    }
    cout << peach;
    system("pause");
    return 0;
}