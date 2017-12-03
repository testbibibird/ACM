#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	unsigned long long int n,i;

	while(cin>>n)
	{
		i= (unsigned long long) (sqrt((double)(1+8*n))-1)/2;

		

		if(n==(1+i)*i/2)
		{
			cout<<1<<'/'<<i<<endl;
		}
		else
		{
			cout<<i+2-(n-(1+i)*i/2)<<"/"<<(n-(1+i)*i/2)<<endl;
		}
	}
}
