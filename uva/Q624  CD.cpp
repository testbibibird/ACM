#include<iostream>
#include<vector>

using namespace std;

int n,t,arr[20]={},tmp,seq[10000]={},prev[10000]={},k;

int main()
{
	

	while(cin>>n)
	{
		cin>>t;

		for(int i = 1 ; i <= t ; ++i )
		{
			cin>>arr[i];prev[i]=-1;//seq[i]=0;
		}
		memset(seq,0,100*100*4);

	//	seq[1] = arr[1];

		for(int i = 1 ; i <= t ; ++i )
		{
			for(int j = n ; j >= arr[i] ; --j )
			{
				//if(seq[j-arr[i] ] + arr[i] <= n )
				if( seq[j - arr[i] ] + arr[i] > seq[j] )
				{
					seq[j] = seq[j-arr[i]]+arr[i];
					prev[j] = arr[i];
				}
			}
		}

		for(int j = seq[n] ; prev[j]>0 ; j-=prev[j] )	cout<<prev[j]<<' ';
		
		

		cout<<"sum:"<<seq[n]<<endl;
		
	}
}

