#include<iostream>
#include<vector>

using namespace std;

int n,arr[10000]={},rs[10000]={};
bool key;

void DFS(int now,int count)
{
	if(count==n)	
	{
		long long sum=0;

		for(int i = 0 ; i < n ; ++i )	sum+=rs[i];

		if(sum%n==0)	
		{
			key = true;;
			cout<<"Yes"<<endl;
			cout<<rs[0];
			for(int i = 1 ; i < n ; ++i )	cout<<' '<<rs[i];
			cout<<endl;
		}

		return ;
	}

	for(int i = now ; i < 2*n-(n-count) && !key ; ++i )
	{
		//cout<<i;
		rs[count] = arr[i];
		DFS(i+1,count+1);
	}
}

int main()
{
	while(cin>>n)
	{
		if(n==0)	break;

		for(int i = 0 ; i < 2*n-1 ; ++i )
		{
			cin>>arr[i];
		}

		key = false;

		DFS(0,0);

		if(!key)	cout<<"No"<<endl;
	}
}