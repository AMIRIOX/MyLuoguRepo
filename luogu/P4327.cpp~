#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const char peter[5][60]={
	"..#..",
	".#.#.",
	"#.X.#",
	".#.#.",
	"..#.."
};
const char wendy[5][60]={
	"..*..",
	".*.*.",
	"*.X.*",
	".*.*.",
	"..*..",

};
char str[20];
char ans[200][200];
int main() {
	/*for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			printf("%c", peter[i][j]);
		}
		puts("");
	}*/
	scanf("%s",str);
	for(int i=0;str[i]!='\0';i++){
		if((i+1)%3) {
			//peter
			int ruler=i*4, inc=4;
			//if(i!=0 && (i+1)%3==1) { ruler++; inc--; }
			for(int a=0;a<5;a++) {
				int row=0;
				for(int b=ruler; b<=ruler+inc;b++) {
					//cout << peter[a][row+1] << endl;
					if(ans[a][b]!='*') ans[a][b]=peter[a][row++];
					else row++;
					//cout << ans[a][b] << endl;
				}
			}
			ans[2][ruler+2]=str[i];
		}else {
			//wendy
			int ruler=i*4;
			// copy wendy[][] to ans[][]
			for(int a=0;a<5;a++) {
				int row=0;
				for(int b=ruler; b<=ruler+4;b++) {
					ans[a][b]=wendy[a][row++];
				}
			}
			ans[2][ruler+2]=str[i];
		}
	}
	for(int i=0;i<5;i++) {
		for(int j=0;j<strlen(str)*4+1;j++) {
			//cout << "??" << strlen(str)*4+1 << endl;
			printf("%c", ans[i][j]);
		}	
		puts("");
	}
	return 0;
}
