#include <iostream>
using namespace std;
int A, B, C;
int now, now2, now3;
struct tb {
	int a;
	int b;
	int c;
	tb(int f,int s,int t) {
		a = f; b = s; c = t;
	}
	bool selfEqaul() {
		if (a == b || a == c || b == c) return true;
		return false;
	}
	bool operator!=(tb other) {
		if (selfEqaul() || other.selfEqaul()) return false;
		if (a == other.a || b == other.b || c == other.c ||
			a == other.b || a == other.c ||
			b == other.a || b == other.c ||
			c == other.a || c == other.b) {
			return false;
		}
		return true;
	}
};
tb getTb(int num) {
	int a = 0,b=0,c=0;
	a = num % 10; 
	b = (num/10)%10; 
	c = num / 100; 

	tb ret(a,b,c);
	return ret;
}
bool wj = true;
int main() {
	cin >> A >> B >> C;
	for (int i = 100;i<=999;i++) {
		if (i%A != 0) continue;

		int x = i / A;
		now = i;
		now2 = x * B;
		now3 = x * C;


		if (now % 10 == 0 || (now / 10) % 10 == 0 || now / 100 == 0) {
			continue;
		}
		if (now2 % 10 == 0 || (now2 / 10) % 10 == 0 || now2 / 100 == 0) {
			continue;
		}
		if (now3 % 10 == 0 || (now3 / 10) % 10 == 0 || now3 / 100 == 0) {
			continue;
		}

		tb a = getTb(now);
		tb b = getTb(now2);
		tb c = getTb(now3);
		/*cout << a.a << " " << a.b << " " << a.c <<", ";
		cout << b.a << " " << b.b << " " << b.c <<", ";
		cout << c.a << " " << c.b << " " << c.c << endl;*/

		if (now2 > 999 || now3 > 999) break;
		
		if (a != b && b!=c && a!=c) {
			wj = false;
			cout << now <<" "<< now2 <<" "<< now3 << endl;
		}
	}
	if (wj) cout << "No!!!";
	return 0;
}