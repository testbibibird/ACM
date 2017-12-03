#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	int n;
	double d,l,pi = 2*acos((double)(0.0)) ;

	cin>>n;

	while(n--)
	{
		cin>>d>>l;

		d/=2;
		l/=2;

		cout.setf(ios::fixed);
		cout.precision(3);
		cout<< l*pi*sqrt(l*l-d*d) <<endl;
	}
}