#include<iostream>

using namespace std;

int main()
{
	long long int n;

	while(cin>>n)
	{
		if(n<0)	break;

		if(n==1)
		{
			n=0;
		}
		
		cout<<n*25<<"%"<<endl;
	}
}
