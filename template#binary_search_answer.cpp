#include <iostream>
using namespace std;
// standard binary answer template

bool check(int x) {}
bool check(double x) {}

// For integer data problems (for precision requirements are not high
int binaryAnswer(int x, int y) {
  int l=x, r=y;
  while(l < y) { // use l<y instead of l<=y
    int mid = l+(r-l)/2;
    if(check(mid)) l=mid+1;  //instead of l=mid
    else r=mid; //instead of r=mid+1
  }
  return l; // r is also ok. they are the same value;
}

// For malevolent, nasty and extremely villaiinous bitch precision related problems
int maxc=50; // Specific problem specific analysis, at most how many times dichotomy
double malevolentNastyExtremelyVillaiinousBitchBinaryAnswer(int x, int y) {
	int l=x, r=y;
	for(int cnt=1; cnt<=maxc; cnt++) {
		double mid=l+(r-l)/2.0;
		if(check(mid)) l=mid; 
		else r=mid;
	}
	return (l+r)/2.0;
}

