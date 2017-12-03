#include<iostream>

using namespace std;

int main()
{
	int n;

	cin>>n;

	while(n>0)
	{
		int p,q;

		cin>>p>>q;

		if(p>q)	cout<<">"<<endl;

		if(p==q)	cout<<"="<<endl;

		if(p<q)	cout<<"<"<<endl;

		--n;
	}
}