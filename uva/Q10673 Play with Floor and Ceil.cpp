#include<iostream>

using namespace std;

int main()
{
	int c;
	long long int a,b,x,k,p,q,temp;

	cin>>c;

	while(c>0)
	{
		cin>>x>>k;

		temp=x/k;

		if(temp*k==x)
		{
			a=temp;
			b=temp;
		}
		else
		{
			a=temp;
			b=temp+1;
		}

		for(int i=0;;++i)
		{
			temp=(x-i*a)/b;

			if(temp*b==x-i*a)
			{
				q=temp;
				p=i;
				break;
			}
		}

		cout<<p<<" "<<q<<endl;

		--c;
	}
}
