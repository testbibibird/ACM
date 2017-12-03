#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int n,sum;

	cout<<"PERFECTION OUTPUT"<<endl;

	while(cin>>n)
	{
		if(n==0)	break;
		
		sum=0;

		for(int i=1;i<n;++i)
		{
			if(n%i==0)
			{
				sum+=i;
			}
		}		

		cout.width(5);
		
		cout<<n;

		if(sum==n)
		{
			cout<<"  PERFECT"<<endl;
		}
		if(sum<n)
		{
			cout<<"  DEFICIENT"<<endl;
		}
		if(sum>n)
		{
			cout<<"  ABUNDANT"<<endl;
		}
	}

	cout<<"END OF OUTPUT"<<endl;
}
