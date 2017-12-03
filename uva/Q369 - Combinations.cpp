#include<iostream>

using namespace std;

int main()
{
	long long int n,k,result,l;

	while(cin>>n>>k)
	{
		if(n==0)	break;

		result=1;

		l=k;

		if(k>n/2)	k=n-k;

		for(int i=1;i<=k;++i)
		{
			result=result*(n-i+1)/i;
		}

		cout<<n<<" things taken "<<l<<" at a time is "<<result<<" exactly."<<endl;

	}


}
