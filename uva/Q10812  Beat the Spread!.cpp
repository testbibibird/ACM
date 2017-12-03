#include<iostream>

using namespace std;

int main()
{
	int num;
	int s,d;
	//int a,b;

	cin>>num;

	while(num!=0)
	{
		cin>>s>>d;

		if((s<d)|| ( s%2==1 && d%2==0) || ( s%2==0 && d%2==1))
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			cout<<(s+d)/2<<" "<<(s-d)/2<<endl;		
		}

		--num;
	}
}