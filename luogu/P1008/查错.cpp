#include <iostream>
using namespace std;
int main()
{
	int num1 = 100;
	while(num1<=333)
	{
		const int N = 9;
		int num2 = num1*2;
		int num3 = num1*3;
		int a[N];
		a[0] = num1/100;a[1] = num2/100;a[2] = num3/100;
		a[3] = (num1/10)%10;a[4] = (num2/10)%10;a[5] = (num3/10)%10;
		a[6] = num1%10;a[7] = num2%10;a[8] = num3%10;
		int True_or_Flase =1;
		for(int n = 0;n<8;n++)
		{
			int j = n;
			
			for(int i = n;i<N-1;i++)
			{
			
				if(a[j]==0 || a[i+1]==0 || a[j]==a[i+1])
				{
					True_or_Flase = 0;
					break;
				}
				
			}
			if(True_or_Flase==0)break;
		}
		if(True_or_Flase==1)cout<<num1<<" "<<num2<<" "<<num3<<endl;
		num1++;
	}
	return 0;	
}









