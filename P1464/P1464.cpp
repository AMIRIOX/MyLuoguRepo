#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;
long long mem[25][25][25];
vector<long long> v;
vector<long long> ni;
long long w(long long a, long long b, long long c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (mem[a][b][c] != -1) {
		return mem[a][b][c];
	}
	else if (a > 20 || b > 20 || c > 20) {
		mem[a][b][c] = w(20, 20, 20);
		//return mem[a][b][c];
	}
	else if (a < b && b < c) {
		mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		//return mem[a][b][c];
	}
	else {
		mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		//return mem[a][b][c];
	}
	return mem[a][b][c];
}
int main() {
	memset(mem, -1, sizeof(mem));
	long long a, b, c;
	int tmp[3];
	while (1) {
		scanf_s("%lld %lld %lld", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		tmp[0] = a, tmp[1] = b, tmp[2] = c;
		if (a > 20) a = 21;
		if (b > 20) b = 21;
		if (c > 20) c = 21;
		v.push_back(w(a, b, c));
		cout << "w(" << tmp[0] << ", " << tmp[1] << ", " << tmp[2] << ") = " <<w(a,b,c)<<endl;
	}

	return 0;
}
