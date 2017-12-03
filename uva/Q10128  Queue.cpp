#include<iostream>

using namespace std;

int main()
{
	int n,p,r,case_num,dp[14][14][14]={};

	cin>>case_num;

	while(case_num--)
	{
		cin>>n>>p>>r;

		--p;
		--r;
		
		dp[1][0][0] = 1;
		for(int i = 2 ; i <= n ; ++i )
		{
			for(int j = 0 ; j <= i && j <= p; ++j )
			{
				for(int k = 0 ; k <= i && k <= r ; ++k )
				{
					if(j==0&& k==0)	dp[i][j][k] = 0;

					else if(j==0)	dp[i][j][k] = dp[i-1][j][k-1] + dp[i-1][j][k]*(i-2);

					else if(k==0)	dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k]*(i-2);
				
					else dp[i][j][k] = dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
				}
			}
		}

		cout<<dp[n][p][r]<<endl;
	}
}
