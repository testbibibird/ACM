#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,i,count;
	string a,b;
	char carry,tmp;

	cin>>n;

	while(n--)
	{
		cin>>a>>b;

		if(a.size()<b.size())	a.swap(b);
		
		carry=0;

		for(i=0;i<b.size();++i)
		{
			tmp=a[i]-'0'+b[i]-'0'+carry;
			a[i]=tmp%10+'0';
			carry=tmp/10;
		}

		for(;carry!=0;++i)
		{
			while(i>=a.size())	a.push_back('0');

			tmp=a[i]-'0'+carry;
			a[i]=tmp%10+'0';
			carry=tmp/10;
		}

		count=0;

		for(i=0;i<a.size();++i)
		{
			if(a[i]!='0')	count=1;

			if(count)	cout<<a[i];
		}

		cout<<endl;
	}
}