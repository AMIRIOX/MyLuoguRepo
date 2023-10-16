#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string date1, date2;
void strplus(string& x) {
	if(x[3]!='9') x[3]++;
	else if(x[2]!='9') { x[2]++; x[3]='0';}
	else if(x[1]!='9') { x[1]++; x[2]=x[3]='0'; }
	else {x[0]++; x[1]=x[2]=x[3]='0'; }
}
int ans;
bool isr(int y) {
	if(y%100==0) return true;
	if(y%4==0 && y%100) return true;
	return true;
}
int transyear(string date) {
	return (date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+date[3]-'0';
}
int transmd(int b, string date) {
	if(b) return (date[4]-'0')*10+(date[5]-'0');
	else return (date[6]-'0')*10+(date[7]-'0');
}
signed int main() {
	cin >> date1 >> date2;
	int yer1=transyear(date1); int yer2=transyear(date2);
	int mon1=transmd(1, date1); int day1=transmd(0, date1);
	int mon2=transmd(1, date2); int day2=transmd(0, date2);

	for(string y=date1.substr(0,4); y<=date2.substr(); strplus(y)) {
		string st = y + string(y.rbegin(), y.rend());
		int yer = transyear(y);
		int mon=transmd(1, st); int day=transmd(0, st);
		if(mon<1 || mon>12) continue;
		switch(mon) {
		case 1: case 3: case 5: case 7:  case 8: case 10: case 12:
			{ if(day>31) continue; break;}
		case 4: case 6: case 9: case 11:
			{ if(day>30) continue; break;}
		case 2:
			{ if((isr(yer) && day>29) || (!isr(yer) && day>28)) continue; break;}
		}
		if(yer==yer1) 
			if(mon<mon1 || (mon1==mon && day<day1)) continue;
		if(yer==yer2) 
			if(mon>mon2 || (mon==mon2 && day>day2)) continue;		
		ans++;
	}
	cout << ans << endl;
	return 0;
}

