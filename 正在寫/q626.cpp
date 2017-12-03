#include<iostream>

using namespace std;

int arr[100][100]={},n,count1,rs[3];

void DFS(int k,int a)
{
	if(k==3)
	{
		cout<<rs[0]<<' '<<rs[1]<<' '<<rs[2]<<endl;
		return;
	}

	for(int i = 0 ; i < n ; ++i )
	{
		if(arr[a][i]==1)
		{
			rs[k] = a+1;
			++count1;
			DFS(k+1,i);
		}
	}
}

int main()
{
	while(cin>>n)
	{
		for(int i = 0 ; i < n ; ++i )
		{
			for(int  j = 0 ; j < n ; ++j )
			{
				cin>>arr[i][j];
			}
		}
		
		for(int i = 0 ; i < n ; ++i )
		{
			DFS(0,i);
		}

		cout<<"total:"<<count1<<endl<<endl;
	}
}