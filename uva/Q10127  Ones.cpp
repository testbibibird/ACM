#include<iostream>

using namespace std;

int main()
{
	long long n,count,m;

	while(cin>>n)
	{
		m=count=1;

		while(m%n)
		{
			++count;
			
			m*=10;
			++m;
			
			m%=n;
		}

		cout<<count<<endl;
	}
}