#include<iostream>
#include<string>

using namespace std;

int c[50][50];
long long g[50][50]={};
long long n ,p;

int main()
{
	string a;

	while(cin>>n)
	{

		if(n==-1)	break;

		for(int i = 0 ; i < n  ;++i )
		{
			cin>>a;
			for(int j = 0 ; j < n ; ++j)
			{
				//c[i][j];
				c[i][j]= a[j]- '0' ;
				g[i][j]=0;
			}
		}
		g[0][0]=1;
		c[n-1][n-1]=1;
		p=0;
	/*	for(int i = 0 ; i < n  ;++i )
		{
			for(int j = 0 ; j < n ; ++j)
			{
		//		cin>>c[i][j];
				cout<<c[i][j];//=0;
			}cout<<endl;
		}*/
		
		for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < n ; ++j )
			{
				if( i + (int)c[i][j]  < n)	
				{
					g[ i+(int)c[i][j] ][j] += g[i][j];
					//cout<<i+(int)c[i][j]<<' '<<j<<' '<<g[ i+(int)c[i][j] ][j]<<endl;
				}
				if( j + (int)c[i][j]  < n)
				{
					g[i][ j+(int)c[i][j] ] += g[i][j];
				//	cout<<i<<' '<<j+(int)c[i][j]<<' '<<g[ i ][j+(int)c[i][j]]<<endl;
				}
			}
		}

	/*	for(int i = 0 ; i < n  ;++i )
		{
			for(int j = 0 ; j < n ; ++j)
			{
		//		cin>>c[i][j];
				cout<<g[i][j];//=0;
			}cout<<endl;
		}*/


		cout<<g[n-1][n-1]<<endl;
	}
}