#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,r,arr[101][101]={},p,c1,c2,count=1;

	while(cin>>n>>r)
	{
		if(n==0&&r==0)	break;

		memset(arr,0,101*101*4);

		//for(int i = 1 ; i <= n ; ++i )	arr[i][i] = 0;

		for(int i = 0 ; i < r ; ++i )
		{
			cin>>c1>>c2>>p;
			arr[c1][c2] = p;
			arr[c2][c1] = p;
		}
		
		for(int k = 1 ; k <= n ; ++k )
			for(int i = 1 ; i <= n ; ++i )
				for(int j = 1 ; j <= n ; ++j )
				{
					arr[i][j] = max(arr[i][j], min(arr[i][k],arr[k][j]));
				}

		cin>>c1>>c2>>p;

		cout<<"Scenario #"<<count++<<endl;
		cout<<"Minimum Number of Trips = "<<ceil((double)p/(double)(arr[c1][c2]-1))<<endl<<endl;
	}
}