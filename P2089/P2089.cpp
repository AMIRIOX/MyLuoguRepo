#include <iostream>
#include <vector>
//问题:生成1 2 3组成的十个数使其和为n
using namespace std;
int shu[15][15];
int tmpa[15];
int cnt = 0;
int n = 0;
int tmp = 0;
vector<int> ans;
void sovle(int ind,int sum) {
	if (ind == 11) {
		if (sum == n) {
			cnt++;
			for (int i = 1; i <= 10; i++) {
				ans.push_back(tmpa[i]);
			}
			ans.push_back(-1);
			return ;
		}
	}
	else {
		for (int i = 1; i <= 3; i++) {
			tmp = i;
			tmpa[ind] = i;
			sovle(ind + 1, sum+tmpa[ind]);
		}
	}
}
int main() {
	cin >> n;
	sovle(1, 0);
	cout << cnt << endl;
	for (int i = 0; i < ans.size(); i++) {
		if(ans[i]==-1){
			cout << endl;
		}
		else if (ans[i + 1] == -1) {
			cout << ans[i];
		}
		else {
			cout << ans[i] <<" ";
		}
	}
	//cout << "ጿ ኈ ቼ ዽ ጿ ኈ";
	return 0;
}