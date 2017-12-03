#include<iostream>

using namespace std;

char c[30][30];
int w,h,bcount;

void DFS(int x,int y)
{
	if( x>=0 && y>=0 && x < h && y < w)
	{
		if(c[x][y]=='.')
		{
			c[x][y]='#';
			bcount++;

			DFS(x-1,y);
			DFS(x+1,y);
			DFS(x,y+1);
			DFS(x,y-1);
		}
	}
}

int main()
{
	while(cin>>w>>h)
	{
		if(w==0&& h==0)	break;

		cin.getline(c[0],25);

		for(int i=0 ; i < h ; ++i)
		{
			cin.getline(c[i],25);
		}

		bcount=0;

		for(int i = 0 ; i < h ; ++i )
		{
			for(int j = 0 ; j < w ; ++j )
			{
				if(c[i][j]=='@')	
				{
					c[i][j]='.';
					DFS(i,j);
				}
			}
		}
		cout<<bcount<<endl;
	}
}