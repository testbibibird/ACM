#include<iostream>

using namespace std;

int main()
{
	int num;
	int a,b;
	int count=1;
	

	cin>>num;

	while(count<=num)
	{
		int sum=0;

		cin>>a>>b;

		if(a%2==0&&b%2==0)
		{
			sum=(a+b)*((b-a-2)/2+1)/2;
		}
		if(a%2==0&&b%2==1)
		{
			sum=(a+1+b)*((b-(a+1))/2+1)/2;
		}
		if(a%2==1&&b%2==0)
		{
			sum=(a+b-1)*((b-1-a)/2+1)/2;
		}
		if(a%2==1&&b%2==1)
		{
			sum=(a+b)*((b-a)/2+1)/2;
		}


		cout<<"Case "<<count<<": "<<sum<<endl;
		
		++count;
	}
	
	

}