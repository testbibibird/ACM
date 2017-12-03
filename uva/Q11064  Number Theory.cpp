#include<iostream>
#include<cmath>

using namespace std;

int prime[10000]={2,3,5,7},c=4;

int phi(int n)
{
	int rs=n,count=1,sum=1; 
	int tmp = sqrt((double)n);
	bool key=true;

	for(int i = 0 ; prime[i] <= tmp && i < c ; ++i ,key = true,count=1) 
	{
		while(n%prime[i]==0)
		{
			n/=prime[i];
			key = false;
			++count;
		}

		sum *= count;
		
		if(!key)		rs = (rs/prime[i])*(prime[i]-1);
				
	}

	if(n!=1)
	{
		rs = (rs/n)*(n-1);
		sum*=2;	
	}
	return rs+sum;
}

int main()
{
	int n;
	bool key=false;

	for(int i = 11 ; i <= 100000 ; i+=2, key = false)
	{
		for(int j = 0 ; prime[j] <= sqrt((double)i) ; ++j )
		{
			if(i%prime[j]==0)	
			{
				key = true;
				break;
			}

		}

		if(!key)
		{
			prime[c++] = i;
		}
	}

	while(cin>>n)
	{
		if(1==n)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<n-phi(n)+1<<endl;
		}
	}

}