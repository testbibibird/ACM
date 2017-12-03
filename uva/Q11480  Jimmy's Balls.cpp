#include<iostream>

using namespace std;

int main()
{
	int count=1;
	long long rs,n;

	while(cin>>n)
	{
		if(n==0)	break;

		n -= 3;

		rs = (n+2)*(n+1)/2;
		rs -= (n/2+1)*3;
		if(n%3==0)
		{
			rs+=2;
		}
		else
		{
			
		}
		//if(n%3==0)	rs-=3;

		cout<<"Case "<<count++<<": "<<rs/6<<endl;
	}
}