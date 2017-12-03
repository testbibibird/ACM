#include<iostream>

using namespace std;

int main()
{
	long long int b,p,n,temp;

	while(cin>>b)
	{
		cin>>p>>n;
 
		if(p==0)	
		{
			cout<<1<<endl;	continue;
		}

		if(n==1)	
		{
			cout<<0<<endl;	continue;
		}
		temp=1;

		for(;p>1;)
		{
			b%=n;
			
			//cout<<b<<" "<<p<<" "<<n<<" "<<temp<<endl;

			if(p%2==0)
			{
				p/=2;
				b*=b;
			}
			else
			{
				--p;
				temp*=b;
			}
			if(temp>=n)	temp%=n;

			//cout<<b<<" "<<p<<" "<<n<<endl;
		}
		
		b=(b*temp)%n;

		cout<<b<<endl;
	}
}
