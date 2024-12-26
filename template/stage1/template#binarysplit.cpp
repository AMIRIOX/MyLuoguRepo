#include <iostream>
using namespace std;
int main() {
  int c = 1;
  int k;
  cin >> k;
  while(k > c) {
    k-=c;
    cout << c << " ";
    c*=2;
  }
  if(k) {
    cout << k << endl;
  }
  return 0;
}
