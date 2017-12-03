#include<iostream>

using namespace std;

int n ,num,* arr,sum,all,index2;

void DFS(bool p,int c)
{
	if(c==num)
	{
		//cout<<sum<<" "<<arr[0]<<" "<<all/2<<endl;
		if( sum+arr[0] > all/2 && sum <= all/2 )
		{
			++index2;
		}

		return ;
	}

	if(c==num-1)
	{
		if(p)
		{
			sum += arr[c];
			DFS(true,c+1);
			sum -= arr[c];
		}
		else	DFS(true,c+1);
	}

	else//if( k!=c )
	{
		if( p )
		{
			sum += arr[c];
			DFS(true,c+1);
			DFS(false,c+1);
			sum -= arr[c];
		}

		else
		{
			DFS(true,c+1);
			DFS(false,c+1);
		}
	}
}

int main()
{
	

	cin>>n;

	while(n--)
	{
		cin>>num;

		arr = new int[num];
		all = 0;

		for( int i = 0 ; i < num ; ++i )	
		{
			cin>>arr[i];
			all += arr[i] ;
		}
		
		for(int i = 0 ; i < num ; ++i )
		{
			index2=0;
			swap(arr[0],arr[i]);
			DFS(0,1);
			DFS(1,1);
			swap(arr[0],arr[i]);
			cout<<"party "<<i+1<<" has power index "<<index2<<endl;
		}
		cout<<endl;
	}

}