#include<iostream>

using namespace std;

int n;
char c[202][202]={};
//bool b[202][202]={};
bool key;
void DFS(int x,int y)
{
	if(x>=0 && y>=0 && x<n && y<n   && !key)
	{
		if(c[x][y]=='w')
		{
			if(y==n-1)	{key = true;return;}
		//cout<<x<<' '<<y<<endl;
		//b[x][y] = true;
			c[x][y]='0';
			DFS(x,y+1);
			DFS(x+1,y);
			DFS(x+1,y+1);
			DFS(x-1,y-1);
			DFS(x,y-1);
			DFS(x-1,y);
			//c[x][y]='w';
		}
	}
}

int main()
{
	int count=1;


	while(cin>>n)
	{
		if(n==0)	break;

		key = false;
		//memset(b,0,202*202);

		cin.getline(c[1],203);

		for(int i = 0 ; i < n ; ++i )
		{
			cin.getline(c[i],n+1);

			//getline(cin,c[i]);
			/*for(int j = 1 ; j <= n ; ++j )
			{
				cin>>c[i][j];
			}*/
		}

	/*	for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < n ; ++j )
				cout<<c[i][j];
			cout<<endl;
		}	*/

		for(int i = 0 ; i < n && !key ; ++i )
		{
			DFS(i,0);
		}

	/*	for( int i = 1 ; i <= n && !key ; ++i )
		{
			if(b[i][n])	{key = true;}
		}*/
		cout<<count++<<' ';
		if(key)	cout<<'W'<<endl;
		else	cout<<'B'<<endl;
	}
}
