#include<iostream>

using namespace std;

int n;
char c[27][27];

void DFS(int x,int y)
{
	if( x>0 && y>0 && x<n+1 && y<n+1 && c[x][y]=='1')
	{
		c[x][y] = '0';

		DFS(x-1,y);
		DFS(x-1,y-1);
		DFS(x,y-1);
		DFS(x+1,y-1);
		DFS(x+1,y);
		DFS(x+1,y+1);
		DFS(x,y+1);
		DFS(x-1,y+1);
	}
}

int main()
{
	int count=1,sum;

	while(cin>>n)
	{
		sum=0;

		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				cin>>c[i][j];
			}
		}
		
		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				if(c[i][j]=='1')
				{
					++sum;
					DFS(i,j);
				}
			}
		}
		


		cout<<"Image number "<<count++<<" contains "<<sum<<" war eagles."<<endl;
	}
}