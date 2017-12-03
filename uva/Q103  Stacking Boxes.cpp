#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool cmp(vector<int> a,vector<int> b)
{
	return a[0] < b[0] ;
}

int main()
{
	int n,k;
	int len[30],ans,prev[30],pos,rs[30],rem[30],remtmp;
	bool key;
	vector<vector<int> > arr(30);
	vector<int> tmp;


	
	while(cin>>k>>n)
	{
		arr.resize(k);

		for(int i = 0 ; i < k ; ++i )
		{
			arr[i].resize(n);
		}
		for(int i = 0 ; i < k ; ++i )
		{
			for(int j = 0 ; j < n ; ++j )
			{
				cin>>arr[i][j];
			}
			len[i] = 1 ;
			prev[i]= -1;
			rem[i] = i+1 ;
		}

		for(int i = 0 ; i < k ; ++i )
		{
			sort(arr[i].begin(),arr[i].end());
		}

	//	sort(arr.begin(),arr.end(),cmp);

		for(int i = 1 ,j; i < k ; ++i )
		{
			tmp = arr[i];
			remtmp = rem[i];
			for( j = i-1 ; j >= 0 ; --j)
			{
				/*if( tmp[0] > arr[j][0])
				{
					break;
				}*/
				key = false;
				for(int l = 0 ; l < n && !key ; ++l )
				{
					if( tmp[l] > arr[j][l] )	key = true;
				//	cout<<l<<endl;
				}

				if( key )
				{	
					break;
				}
				arr[j+1] = arr[j];
				rem[j+1] = rem[j];
			}
			arr[j+1] = tmp;
			rem[j+1] = remtmp;
		}

/*		for(int i = 0 ; i < k ; ++i )
		{
			for(int j = 0 ; j < n ; ++j )	cout<<arr[i][j]<<' ';
			cout<<endl;
			//sort(arr[i],arr[i]+n);
		}*/

		for(int i = 0 ; i < k ; ++i )
		{
			for(int j = 0 ; j < i ; ++j )
			{
				key = true;;

				for(int l = 0 ; l < n ; ++l )
				{
					if( arr[i][l] <= arr[j][l] )	key = false;	
				}

				if( key )
				{
					if( len[i] < len[j] + 1 )
					{
						prev[i] = j ;
						len[i] = len[j]+1;
					}
				}
			}
		}
		ans = 0 ;

		for(int i = 0 ; i < k ; ++i )
		{
			if(len[i]>ans)	
			{
				ans = len[i];
				pos = i ;
			}
		}

		for(int j = ans - 1 ; pos != -1 ; pos = prev[pos], --j )
		{
			rs[j] = pos;
	//		cout<<pos<<' ';
		}
		cout<<ans<<endl;
		cout<<rem[rs[0]];
		for(int i = 1 ; i < ans ; ++i )
		{
			cout<<' '<<rem[rs[i]];
		}cout<<endl;

		//for(int i = 0 ; i < k ; ++i )	cout<<rem[i]<<' ';
		//cout<<endl;

		arr.clear();

		
	}
}