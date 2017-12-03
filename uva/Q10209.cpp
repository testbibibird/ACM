#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double a;

	double pi=2*acos(0.0);

	while(cin>>a)
	{
		cout<<fixed<<setprecision(3);
		cout<<a*a*(1-sqrt(3)+pi/3)<<" ";
		cout<<a*a*(pi/3+2*sqrt(3)-4)<<" ";
		cout<<a*a*(4-sqrt(3)-pi*2/3)<<endl;
	}


}
