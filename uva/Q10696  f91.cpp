#include<iostream>

using namespace std;



int main()
{
	int n;
	int a=91;

	cin>>n;

	while(n!=0)
	{
		if(n>100)
		{
			cout<<"f91("<<n<<") = "<<n-10<<endl;
		}
		else
		{
			cout<<"f91("<<n<<") = "<<a<<endl;
		}
		cin>>n;
	}
}


