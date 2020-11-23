#include <iostream>
using namespace std;
// standard binary answer template

bool check(int x) {}

int binaryAnswer(int x, int y) {
  int l=x, r=y;
  while(l < y) { // use l<y instead of l<=y
    int mid = l+(r-l)/2;
    if(check(mid)) l=mid+1;  //instead of l=mid
    else r=mid; //instead of r=mid+1
  }
  return l; // r is also ok. they are the same value;
}
