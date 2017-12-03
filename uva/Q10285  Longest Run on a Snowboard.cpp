#include<iostream>
#include<string>

using namespace std;

int arr[102][102]={};
int dp[102][102]={};
int t,m,n,rs;

int DFS(int x,int y)
{
	/*if( 0<x && x <= n && y < 0 && y <= m )
	{

	}*/
	if(dp[x][y]!=0){
	//	cout<<x<<' '<<y<<endl;
		return dp[x][y];
	}
	if( arr[x+1][y] < arr[x][y] )	dp[x][y] = max(dp[x][y],DFS(x+1,y)+1);
	if( arr[x-1][y] < arr[x][y] )	dp[x][y] = max(dp[x][y],DFS(x-1,y)+1);
	if( arr[x][y+1] < arr[x][y] )	dp[x][y] = max(dp[x][y],DFS(x,y+1)+1);
	if( arr[x][y-1] < arr[x][y] )	dp[x][y] = max(dp[x][y],DFS(x,y-1)+1);
	if( arr[x+1][y] >= arr[x][y] && arr[x-1][y] >= arr[x][y] && arr[x][y+1] >= arr[x][y] && arr[x][y-1] >= arr[x][y])	dp[x][y] = 1;
	
	return dp[x][y];
}

int main()
{
	
	string a;

	cin>>t;

	while(t--)
	{
		memset(arr,1,102*102*4);
		memset(dp,0,4*102*102);
		rs=0;

		cin>>a>>n>>m;

		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= m ; ++j )
			{
				cin>>arr[i][j];
			}
		}

		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= m ; ++j )
			{
				rs = max(DFS(i,j),rs);
			//	cout<<rs<<' '<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}

		cout<<a<<": "<<rs<<endl;
	}
}