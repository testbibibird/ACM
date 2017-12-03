#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
class node
{
public:
	double x;
	double y;
};
double dis(double a1,double a2,double b1,double b2)
{
	return sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
}

int main()
{
	double gx,gy,dx,dy;
	int n,count=0;
	node arr[1000];

	while(cin>>n>>gx>>gy>>dx>>dy)
	{
		//if(count)	cout<<endl;

		for(int i = 0 ; i < n ; ++i )
		{
			cin>>arr[i].x>>arr[i].y;
		}

		int i;

		for( i = 0 ; i < n ; ++i )
		{
			if( 2*dis(arr[i].x,arr[i].y,gx,gy) <= dis(arr[i].x,arr[i].y,dx,dy) )	break;
		}

		if(i==n)
		{
			cout<<"The gopher cannot escape."<<endl;
		}
		else
		{
			cout.setf(ios::fixed);
			cout.precision(3);
			cout<<"The gopher can escape through the hole at ("<<arr[i].x<<','<<arr[i].y<<")."<<endl;
		}
		++count;
	}

}