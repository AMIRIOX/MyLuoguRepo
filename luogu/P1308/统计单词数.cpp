#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char toOther(char a){
	if((int)a>=65 && (int)a<=90){
		return a+32;
	}else{
		return a-32; 
	}
}
int main() {
	string word;
	string arti;
	vector<char> cv;
	vector<vector<char> > vv;
	
	//cin >> word;
	//cin.get();
	gets(word);
	gets(arti);
	//cout << arti << endl;
	
	/*int a=0,b=0;
	bool reach = false;
	for(int i=0;i<all.size();i++){
		if(all[i]=='\n') reach=true;
		if(!reach){
			if(all[i] != '\n') word[a++] = all[i];
		}else{
			if(all[i] != '\n') word[a++] = all[i];
		}
	}*/
	
	for(int i=0;i<arti.size();i++){
		if(arti[i]!=' '){
			cv.push_back(arti[i]);
			//cout << tmp[index-1];
		}
		else{
		//	v.push_back(tmp);
		//	index = 0;
			if(cv.size()<=0) continue;
			vv.push_back(cv);
			cv.clear();
		}
	}
	vv.push_back(cv);
	
	
	
	
	//测试输入 
	/*cout << word <<endl; 
	for(int i=0;i<vv.size();i++){
		for(int j=0;j<vv[i].size();j++){
			cout << vv[i][j];
		}
		cout <<"+";
	}*/ 
	
	//核心代码
	int pos = -1;
	int cnt = 0;
	//1.vv[i][j]为句子中的第i+1个词中的第j+1个字母 
	for(int i=0;i<vv.size();i++){
		
		for(int j=0;j<word.size();j++){
			char owj = toOther(word[j]);
			char ovj = toOther(vv[i][j]);
			if(word[j]==vv[i][j] || owj==vv[i][j] || ovj == word[j]){
				pos = j;
				if(j==word.size()-1){
					if(j==vv[i].size()-1) cnt++;
					else{
						pos = -1;
						break;
					}
				}
			}else{
				break;
			}
		}
		
	} 
	if(--pos==-1) cout << "-1";
	else cout << cnt << " " << pos;

	return 0;
}
