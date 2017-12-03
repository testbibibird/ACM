#include<iostream>

using namespace std;

int main()
{
	int num,num2,n;
	char c;

	cin>>n;

	while(n--)
	{
		cin>>hex>>num;
		cin>>c;
		cin>>hex>>num2;

		for(int i = 12 ; i >= 0 ; --i )
		{
			cout<<((num>>i)&1);
		}

		cout<<" "<<c<<" ";
		for(int i = 12 ; i >= 0 ; --i )
		{
			cout<<((num2>>i)&1);
		}

		if(c=='+')
		{
			num+=num2;
		}
		else
		{
			num-=num2;
		}

		cout<<" = "<<num<<endl;
	}
}