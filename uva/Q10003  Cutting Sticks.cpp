#include<iostream>

using namespace std;

int main()
{
	int l,n,arr[52]={},c[52][52]={};

	while(cin>>l)
	{
		if(l==0)	break;

		cin>>n;

		arr[n+1] = l ;
		memset(c,0,52*52*4);

		for(int i = 1 ; i <= n ; ++i )
		{
			cin>>arr[i];
		}

		n+=2;

		for(int i = 2 ; i < n ; ++i )
		{
			for(int j = 0 ; j < n-i ; ++j )
			{
				for(int k = j+1 ; k < i+j ; ++k )
				{
					if(c[j][i+j]==0)
						c[j][i+j] =  c[j][k] + c[k][j+i] + arr[i+j] - arr[j];
					else
						c[j][i+j] = min( c[j][i+j] , c[j][k] + c[k][j+i] + arr[j+i] - arr[j] );
				}
			}
		}


		cout<<"The minimum cutting is "<<c[0][n-1]<<'.'<<endl;
	}
}