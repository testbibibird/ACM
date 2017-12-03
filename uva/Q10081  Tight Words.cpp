#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double arr[10][101]={},rs[10][101]={};
	double ans;

	for(int i = 0 ; i < 10 ; ++i )	
	{
		arr[i][1] = 1;
		rs[i][1] = i+1;
	}
	for(int i = 1 ; i < 101 ; ++i )	
	{
		arr[0][i] = 1;
		rs[0][i] = 1;
	}
	for(int k = 1 ; k < 10 ; ++k )
	{
		for(int j = 2 ; j < 101 ; ++j )
		{
			for(int i = 0 ; i <= k ; ++i )
			{
				if( i == 0 ) 
					arr[i][j] = arr[i][j-1]+arr[i+1][j-1];
				else if( i == k )
					arr[i][j] = arr[i-1][j-1]+arr[i][j-1];
				else	
					arr[i][j] = arr[i-1][j-1]+arr[i][j-1]+arr[i+1][j-1];
			}

			for(int i = 0 ; i <= k ; ++i )
			{
				rs[k][j] += arr[i][j];
			}

			
		}

		
	}

	int _k,n;

	while(cin>>_k>>n)
	{
		ans = double(rs[_k][n]) / pow((double)(_k+1),(double)n);

		//cout<<rs[_k][n]<<' ';
		cout<<fixed<<setprecision(5)<<ans*100<<endl;
	}
}
