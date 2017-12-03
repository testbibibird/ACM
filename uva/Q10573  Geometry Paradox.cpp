#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int n;
	double result,pi= 2*acos(0.0);
	string a;

	cin>>n;
	getline(cin,a);

	while(n--)
	{
		getline(cin,a);

		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(4);

		if(a.find(' ')==-1)
		{
			result=atof(a.c_str());
			cout<<result*result*pi/8<<endl;
		}
		else
		{
			string tmp(a,0,a.find(' '));
			result = atof( tmp.c_str() );
			tmp=a.substr(a.find(' '));
			cout<<result * atof(tmp.c_str()) * 2 * pi <<endl;
		}

		
	}
}