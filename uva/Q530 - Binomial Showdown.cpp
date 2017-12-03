#include<iostream>

using namespace std;

int main()
{
	int n,k;
	
	long long int result;

	while(cin>>n>>k)
	{
		if(n==0)	break;
		
		result=1;

		if(k>n/2)	k=n-k;
			
		for(int i=1;i<=k;++i)
		{
			result=result*(n-i+1)/i;
		}


		cout<<result<<endl;;
	}
}
