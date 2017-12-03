#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double a,b,c,rs;

	while(cin>>a>>b>>c)
	{

		rs = sqrt( (a+b+c) * (b+c-a) * (a+c-b) * (a+b-c))/3;

		cout.setf(ios::fixed);
		cout.precision(3);

		if(rs>0)	cout<<rs<<endl;
		else	cout<<-1.000<<endl;;
	}
}