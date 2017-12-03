#include<iostream>

using namespace std;

int main()
{
	int n ;

	while(cin>>n)
	{
		if(n%2==0)	cout<<(n*3)/2<<endl;
		else	cout<<((n-1)*3)/2+1<<endl;
	}
}