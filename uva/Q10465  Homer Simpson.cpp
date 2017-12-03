#include<iostream>

using namespace std;;

int main()
{
	int m,n,t,w[10000]={},c[10000]={};

	while(cin>>m>>n>>t)
	{
		memset(c,0,10000*4);
		memset(w,0,10000*4);

		if(n < m )	swap(m,n);

		for(int i = m ; i <= t ; ++i )
		{
			if( w[i-m]+m > w[i] )
			{
				c[i] = c[i-m] + 1;
				w[i] = w[i-m] + m;
			}
		}
		/*for(int i = 0 ; i <= t ; ++i  )
		{
			cout<<w[i]<<' ';
		}cout<<endl;*/
		for(int i = n ; i <= t ; ++i )
		{
			if( w[i-n]+n > w[i] )
			{
				c[i] = c[i-n] + 1;
				w[i] = w[i-n] + n;
			}
		}
/*
		for(int i = 0 ; i <= t ; ++i  )
		{
			cout<<w[i]<<' ';
		}
		cout<<endl;*/
		if(w[t]==t)
		{
			cout<<c[t]<<endl;
		}
		else
		{
			cout<<c[t]<<' '<<t-w[t]<<endl;
		}
	}
}