#include<iostream>

using namespace std;

int main()
{
	double v,t;

	while(cin>>v>>t)
	{
		double kilo=0;

		if(t!=0)
		kilo=0.5*(v/t)*2*t*2*t;

		cout<<kilo<<endl;

	}
}