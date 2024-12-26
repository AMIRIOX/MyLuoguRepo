#include <iostream>
#include <string>
#include <climits>
#include <cstring>
using namespace std;
int word[27];
int main(){
	//我会用string数组,但我就是嫌麻烦 
	memset(word,0,27);
	string str1;
	string str2;
	string str3;
	string str4;
	
	getline(cin,str1);
	getline(cin,str2);
	getline(cin,str3);
	getline(cin,str4);
	
	//cout << str1<<"----"<<str2<<"----"<<str3<<"----"<<str4<<"----";
	
	int maxn=-1;
	int pos=-1;
	int min=INT_MAX;
	for(int i=0;i<str1.size();i++){
		int index=(int)str1[i]-64;
		//cout << index << " ";
		if(index<0) continue;
		word[index]++;
	}
	for(int i=0;i<str2.size();i++){
		int index=(int)str2[i]-64;
		//cout << index << " ";
		if(index<0) continue;
		word[index]++;
	}
	for(int i=0;i<str3.size();i++){
		int index=(int)str3[i]-64;
		//cout << index << " ";
		if(index<0) continue;
		word[index]++;
	}
	for(int i=0;i<str4.size();i++){
		int index=(int)str4[i]-64;
		//cout << index << " ";
		if(index<0) continue;
		word[index]++;
	}
	for(int i=1;i<=26;i++){
		if(word[i]>maxn) {
			maxn=word[i];
			pos=i;
		}
		if(word[i]<maxn){
			min=word[i];
		}
		//cout << word[i] << " ";
	}
	//cout << maxn <<pos;
	
	bool flag=false;
	//int row[maxn+2];
	//for(int i=1;i<=maxn+1;i++){
	//	row[i]=i;
		//cout << row[i] <<" ";
	//}
	for(int h=1;h<=maxn+1;h++){
		if(h==maxn+1) {
			cout <<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
			break;
		}
		for(int i=1;i<=26;i++){
			if(h>=maxn-word[i]+1){
				cout <<"* ";
				//for(int j=i+1;j<=26;j++){
				//	if(h>=maxn-word[i]+1)
				//}
			}else{
				cout <<"  ";
				//if(!flag) cout <<"\n";
				//else cout << " ";
			}
			
		}
		cout << endl;
	}

	
	
	
	return 0;
}


