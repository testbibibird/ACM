#include<iostream>

using namespace std;

int main()
{
	long long m,n,summ,sumn;

	while(cin>>m>>n)
	{
		if( m<0 && n<0 )	break;

		--m;
		summ=sumn=1;

		for(int ten = 10 ; m/ten > 0 ; ten*=10 )
		{
			summ+=m/ten;
		}

		for(int ten = 10 ; n/ten > 0 ; ten*=10 )
		{
			sumn+=n/10;
		}

		cout<<sumn-summ<<endl;
	}
}