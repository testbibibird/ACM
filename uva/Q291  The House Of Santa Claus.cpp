#include<iostream>

using namespace std;

bool arr[5][5]={0,1,1,0,1,
				1,0,1,0,1,
				1,1,0,1,1,
				0,0,1,0,1,
				1,1,1,1,0};
bool visit[5]={};

int pi[5]={};

int rs[9]={1};

void DFS(int s,int k)
{
	//visit[i] = true;

	if(k==8)
	{
		rs[8]  = s+1;
		for(int i = 0 ; i <= k ; ++i )	cout<<rs[i];
		cout<<endl;
		return;
	}

	for(int i = 0 ; i < 5 ; ++i )
	{
		if(arr[s][i])	
		{
			arr[s][i] = 0;
			arr[i][s] = 0;
			rs[k] = s+1 ;
			DFS(i,k+1);
			arr[s][i] = 1;
			arr[i][s] = 1;
			
		}
	}
	
}

void DFS()
{
	DFS(0,0);
}

int main()
{
	DFS();
}