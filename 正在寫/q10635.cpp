#include<iostream>

using namespace std;

int main()
{
	int casenum,c=1,n,p,q;
	long long arr[250*250+1]={},tmp2,tmp;
	int pa[250*250+1];
	int pb[250*250+1];

	cin>>casenum;

	while(c<=casenum)
	{
		cin>>n>>p>>q;

		memset(arr,0,(250*250+1)*4);
		//memset(pa,0,250*250+1*)

		for(int i = 0 ; i <= p ; ++i )
		{
			cin>>pa[i];
		}
		for(int i = 0 ; i <= q ; ++i )
		{
			cin>>pb[i];
		}

		for(int i = 1 ; i <= p ; ++i )
		{
			for(int j = 1 ; j <= q ; ++j)
			{
				tmp2 = arr[i];

				if( pa[i] == pb[j] )	arr[j] = tmp + 1;//arr[i][j] = arr[i-1][j-1] + 1;

				else	arr[j] = max( arr[j] , arr[j-1] );

				tmp = tmp2;
			}
		}

		cout<<"Case "<<c++<<": "<<arr[q]+1<<endl;
	}
}