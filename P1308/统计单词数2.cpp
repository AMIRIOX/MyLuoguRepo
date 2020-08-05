#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;
char word[20];
char arti[1000020];

void DXZM(char *str){
	for(int index=0; str[index];index++){
		str[index] = toupper(str[index]);
	}
} 
int main(){
	memset(word,0,20);
	memset(arti,0,1000020);
	gets(word);
	gets(arti);
	DXZM(word);
	DXZM(arti);
	
	int length = strlen(word);
	int sum=0;//找到的单词次数 
	int ans=-1;//第一次出现 
	char* pos=nullptr;
	char* last = arti;
	while(pos=strstr(last,word)){
		cout << "g";
		if(pos!=nullptr && (pos==arti || *(pos-1)==' ') && (*(pos+length)=='\0'||*(pos+length)==' ')){
			if(ans == -1){
				ans = pos-arti;
			}
			sum++;
		}
		last =  pos+length;
	}
	if(ans==-1) cout <<"-1";
	else cout <<sum<<" "<<ans;
	return 0;
} 
