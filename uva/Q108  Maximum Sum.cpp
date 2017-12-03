#include<iostream>

using namespace std;

int main()
{
	int n,arr[100][100]={},max = -10000000,dp[100]={};

	cin>>n;

	for(int i = 0 ; i < n ; ++i )
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
			dp[0] = arr[k][0];
			if(dp[0] > max)	max = dp[0];

			for(int j = 1 ; j < n ; ++j )
			{
				dp[j] = dp[j-1] + arr[k][j];

				if(dp[j] > max )	max = dp[j];
				if(dp[j] < 0) dp[j] = 0 ;
			}
		}

	}

	cout<<max<<endl;
}
