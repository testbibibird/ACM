#include<iostream>

using namespace std;



int main()
{
	double n,r,num,outnum,count=1;


	while(cin>>n)
	{
		if(count!=1)	cout<<endl;

		r=n-0.5;
		num=0,outnum=0;

		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				if( r*r > i*i + j*j )	
				{
					++outnum;
				}
				else if (r*r > (i-1)*(i-1) + (j-1)*(j-1) )
				{
					++num;
				}
			}
		}

		cout<<"In the case n = "<<n<<", "<<4*num<<" cells contain segments of the circle."<<endl;
		cout<<"There are "<<outnum*4<<" cells completely contained in the circle."<<endl;

		++count;
	}
}