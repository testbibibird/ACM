#include<iostream>

using namespace std;

int main()
{
	int n,m,arr[100][100]={},max = -10000000,dp[100]={};

	while(cin>>m>>n)
	{
	if(m==0 && n==0 )	break;
	max = -1;
	for(int i = 0 ; i < m ; ++i )
	{
		for(int j = 0 ; j < n ; ++j )
		{
			cin>>arr[i][j];

			for(int k = 0 ; k < i ; ++k )
			{
				arr[k][j] += arr[i][j];
			}
		}

		for(int k = 0 ; k <= i ; ++k )
		{

			if(arr[k][0] == 0)	dp[0] = i-k+1;
			else dp[0] = 0;
			if(dp[0] > max)	max = dp[0];

			for(int j = 1 ; j < n ; ++j )
			{
				if(arr[k][j] == 0)
				dp[j] = dp[j-1] + i-k+1;
				else dp[j] = 0;

				if(dp[j] > max )	max = dp[j];
				
			}
		}

	}

		cout<<max<<endl;
	}
}

