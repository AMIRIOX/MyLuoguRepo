#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    int a[5] = {0, 1, 2, 3, 4};
    int *p = &a[3];
    cout << p[-1] << endl;
    return 0;
}
