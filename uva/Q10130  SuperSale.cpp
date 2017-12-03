#include<iostream>

using namespace std;

class node
{
public:int p,w;
};

int main()
{
	int sum,t,n,g,c[1001][31],mw;
	node arr[1000];

	cin>>t;

	while(t--)
	{
		cin>>n;
		sum=0;

		for(int i = 0 ; i < n ; ++i )
			cin>>arr[i].p>>arr[i].w;

		cin>>g;
		memset(c,0,1001*31*4);
		for(int l = 0 ; l < g ; ++l)
		{
			cin>>mw;

			memset(c,0,1001*31*4);
			for(int i = 0 ; i < n ; ++i )
			{
				for(int j = 0 ; j < arr[i].w ; ++j )	c[i+1][j] = c[i][j]; 

				for(int j = arr[i].w ; j <= mw ; ++j )
				{
					c[i+1][j] = max(c[i][j],c[i][j-arr[i].w] + arr[i].p);
				}

				
			}
			/*for(int i = 0 ; i <= n ; ++i )
			{
				for(int j = 0 ; j <= mw ; ++j )
				{
					cout<<c[i][j]<<' ';
					//c[i+1][j] = max(c[i][j],c[i+1][j-arr[i].w] + arr[i].p);
				}
				cout<<endl;
			}*/

			
		//	cout<<c[n][mw]<<'x'<<endl;
			sum += c[n][mw];	
		}
		cout<<sum<<endl;
		
	}
}