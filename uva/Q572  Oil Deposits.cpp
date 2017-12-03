#include<iostream>

using namespace std;

int m,n;
char c[102][102]={};

void DFS(int x,int y)
{
	if( x > 0 && y > 0 && x <= m && y <= n && c[x][y] == '@' )
	{
		c[x][y] = '*';

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
	int count;

	while(cin>>m>>n)
	{
		if(m==0&&n==0)	break;

		count=0;

		memset(c,0,102*102);

		for(int i = 1 ; i <= m ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				cin>>c[i][j];
			}
		}

		/*for(int i = 1 ; i <= m ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				cout<<c[i][j];
			}cout<<endl;
		}*/

		for( int i = 1 ; i <= m ; ++i )
		{
			for( int j = 1; j <= n ; ++j )
			{
				if(c[i][j]=='@')	
				{
					++count;
					DFS(i,j);
				}
			}
		}

		cout<<count<<endl;
	}
}