#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double l,w;

	while(cin>>l>>w)
	{
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<(l+w-sqrt(l*(l-w)+w*w))/6+1e-7<<" 0.000 "<<min(l,w)/2+1e-7<<endl;
	}
}