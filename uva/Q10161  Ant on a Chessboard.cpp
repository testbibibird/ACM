#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,x,y,tmp,travel,i;

	while(cin>>n)
	{
		if(n==0)	break;

		tmp = sqrt((double)n);

		if(n==tmp*tmp )
		{	
			if(tmp%2==1)
			{
				cout<<1<<' '<<tmp<<endl;
			}
			else
			{
				cout<<tmp<<' '<<1<<endl;
			}
		}
		else
		{
			if( tmp%2==1 )
			{
				for( x=1 , y=tmp+1  ,travel = tmp*tmp+1 , i = 1 ; travel<n &&  i < tmp+1 ; ++travel , ++x ,++i )
				{}
				for( ; travel < n ; ++travel , --y ){}
			}
			else
			{
				for( x=tmp+1 , y=1  ,travel = tmp*tmp+1 , i = 1 ; travel<n &&  i < tmp+1 ; ++travel , ++y ,++i )
				{}
				for( ; travel < n ; ++travel , --x ){}
			}

			cout<<x<<' '<<y<<endl;
		}
	}
}