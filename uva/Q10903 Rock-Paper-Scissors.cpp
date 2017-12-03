#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	int n,k,p1,p2,count=0;
	string a,b;

	while(1)
	{
		
		
		cin>>n;

		if(n==0)	break;

		cin>>k;
		
		if(count!=0)	cout<<endl;

		double *win=new double [n];
		double *lose=new double [n];
		int *draw=new int [n];

	
		
		for(int i=0;i<n;++i)
		{
			win[i]=0;
			lose[i]=0;
			draw[i]=0;
		}

		for(int i=0; i < k*n*(n-1)/2 ;++i)
		{
			cin>>p1>>a>>p2>>b;

			--p1;
			--p2;
		
			if(a==b)
			{
				draw[p1]++;
				draw[p2]++;
			}
			if(a=="paper"&&b=="rock")
			{
				win[p1]++;
				lose[p2]++;
			}
			if(a=="rock"&&b=="paper")
			{
				win[p2]++;
				lose[p1]++;
			}
			if(a=="scissors"&&b=="paper")
			{
				win[p1]++;
				lose[p2]++;
			}
			if(a=="paper"&&b=="scissors")
			{
				win[p2]++;
				lose[p1]++;
			}
			if(a=="scissors"&&b=="rock")
			{
				win[p2]++;
				lose[p1]++;
			}
			if(a=="rock"&&b=="scissors")
			{
				win[p1]++;
				lose[p2]++;
			}
		
		}	

		cout.setf(ios::fixed);
		cout.precision(3);

		for(int i=0;i<n;++i)
		{
			if(draw[i]==(n-1)*k)
			{
				cout<<"-"<<endl;
			}
			else
			{
				cout<<win[i]/(lose[i]+win[i])<<endl;
			}
		}

		++count;

	}

}
