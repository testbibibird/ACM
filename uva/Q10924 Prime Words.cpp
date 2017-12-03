#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool prime(int);

int main()
{
	string n;
	int sum=0;

	//cin>>n;

	while(cin>>n)
	{
		sum=0;

		for(unsigned int i=0;i<n.size();++i)
		{
			if(n[i]>96)
			{
				sum+=static_cast<int>(n[i]-96);
			}
			else
			{
				sum+=static_cast<int>(n[i]-38);
			}
		}


		if(prime(sum))
		{
			cout<<"It is a prime word."<<endl;
		}
		else
		{
			cout<<"It is not a prime word."<<endl;
		}

	}
	

}

bool prime(int a)
{

	int m=sqrt(static_cast<double>(a));
	int quotient;


	for(int i=1;i<=m;++i)
	{
		quotient=a/i;

		if(quotient*i==a&&i!=1&&i!=a)
		{
			return false;

		}

	}

	return true;
}