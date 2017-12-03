#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	string a(1,'0'),b(1,'1'),c(1,'1');
	char carry,temp;
	string arr[5001];
	arr[0]=a;
	arr[1]=b;

	for(int k=2;k<5001;++k)
	{
		carry=0;

			c=b;
		
			int i,j;

		for(i=b.size()-1,j=a.size()-1;j>=0;--i,--j)
		{
			temp=b[i];

			b[i]=(a[j]-'0'+b[i]-'0'+carry)%10+'0';

			carry=(a[j]-'0'+temp-'0'+carry)/10;
		}

		for(;i>=0;--i)
		{
			temp=b[i];

			b[i]=(b[i]-'0'+carry)%10+'0';

			carry=(temp-'0'+carry)/10;
		}

		if(i==j&&carry>0)	b.insert(0,1,carry+'0');

		a=c;
			
		arr[k]=b;
	}
	while(cin>>n)
	{
		cout<<arr[n]<<endl;
	}
}
