#include<iostream>
#include<iomanip>

using namespace std;

bool d(double ,double ,double);

int main()
{
	double area,n,a,count,x,y;

	while(cin>>n)
	{
		if(n==0)	break;
		
		cin>>a;

		count=0;
		
		for(int i=0;i<n;++i)
		{
			cin>>x>>y;

			if(d(x,y,a))
			{
				++count;
			}
		}

		cout.setf(ios::fixed);
		cout.precision(5);

		cout<<count*a*a/n<<endl;

		
	}
}

bool d(double x,double y,double a)
{
	double c1,c2,c3,c4;

	c1=(x*x+y*y);
	c2=((x-a)*(x-a)+y*y);
	c3=((x-a)*(x-a)+(y-a)*(y-a));
	c4=(x*x+(y-a)*(y-a));

	if(c1 < a*a && c2< a*a && c3<a*a && c4<a*a )	return true;

	return false;
	
}
