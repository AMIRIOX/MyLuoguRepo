#include <iostream>
using namespace std;
int a[10010];
int Eratosthenes(int n) {
  a[0] = a[1] = 1;
  int cnt = 0;
  for (int i = 2; i * i <= n; i++) {
    if (a[i] == 0) {
      for (int j = i << 1; j <= n; j += i) a[j] = 1;
      cnt++;
    }
  }
  return cnt;
}
int main() {
  int n;
  scanf("%d", &n);
  // cout << "total: " << Eratosthenes(n) << endl;
  Eratosthenes(n);
  for (int i = 1; i <= n; i++)
    if (!a[i]) printf("%d ", i);
  return 0;
}