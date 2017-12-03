#include<iostream>

using namespace std;

char c[81][81];
char c2[81][81];
int n,state,ucount;

void DFS2(int x,int y,char color)
{
	if(y==n && c[x][y] == color && color=='W')	state=1;
	if(x==n && c[x][y] == color && color=='B')	state=2;
	if(y==n && c[x][y] == 'U' && color=='W' && state!=1 && state!=2 )	state=3;
	if(x==n && c[x][y] == 'U' && color=='B' && state ==0 )	state=4;

	if( x>0 && y>0 && x<=n && y<=n && c[x][y]==color )
	{
		c[x][y]='0';
		DFS2(x-1,y,color);
		DFS2(x,y-1,color);
		DFS2(x+1,y,color);
		DFS2(x,y+1,color);
	//	c[x][y]='0';
	}
}
void DFS(int x,int y,char color)
{
	//if( c[x][y]==color || c[x][y]=='U' )
	
	char tmp;

	if(y==n&&color=='W')
	{
		//cout<<x<<' '<<y<<' '<<color<<' '<<ucount<<endl;

		if(ucount==0)
		{
			if(y==n && c[x][y] == color && color=='W')	state=1;
			if(x==n && c[x][y] == color && color=='B')	state=2;
			if(y==n && c[x][y] == 'U' && color=='W' && state!=1 && state!=2 )	state=3;
			if(x==n && c[x][y] == 'U' && color=='B' && state ==0 )	state=4;
			return;
		}
	
		else if(ucount==1)	
		{
			if(y==n && c[x][y] == color && color=='W' && state!=1 && state!=2 )	state=3;
			if(x==n && c[x][y] == color && color=='B' && state ==0 )	state=4;
			return;
		}

		//c[x][y]='0';
		return;
	}
	else 	if(x==n&&color=='B')
	{
		//cout<<x<<' '<<y<<' '<<color<<' '<<ucount<<endl;

		if(ucount==0)
		{
			if(y==n && c[x][y] == color && color=='W')	state=1;
			if(x==n && c[x][y] == color && color=='B')	state=2;
			if(y==n && c[x][y] == 'U' && color=='W' && state!=1 && state!=2 )	state=3;
			if(x==n && c[x][y] == 'U' && color=='B' && state ==0 )	state=4;
			return;
		}
	
		else if(ucount==1)	
		{
			if(y==n && c[x][y] == color && color=='W' && state!=1 && state!=2 )	state=3;
			if(x==n && c[x][y] == color && color=='B' && state ==0 )	state=4;
			return;
		}

		//c[x][y]='0';
		return;
	}

	if( x>0 && y>0 && x<=n && y<=n && c[x][y]==color || c[x][y] == 'U' && ucount==0)
	{
		//cout<<x<<' '<<y<<' '<<color<<endl;
		if(c[x][y]=='U')	ucount++;

		tmp = c[x][y];
		c[x][y]='0';
		bool k1,k2,k3,k4;

		k1=k2=k3=k4=true;

		if(c[x+1][y]==color){		
			DFS(x+1,y,color);
			k1 = false;
		}
		if(c[x][y-1]==color){
			DFS(x,y-1,color);
			k2 = false;
		}
		if(c[x-1][y]==color){
			DFS(x-1,y,color);
			k3=false;
		}
		if(c[x][y+1]==color){
			DFS(x,y+1,color);
			k4=false;
		}

		if(k1)	DFS(x+1,y,color);
		if(k2)	DFS(x,y-1,color);
		if(k3)	DFS(x-1,y,color);
		if(k4)	DFS(x,y+1,color);
	//	c[x][y] = tmp;
		//cout<<c[x][y];

		if(tmp=='U')	
		{
			ucount--;
			c[x][y]=tmp;
		}
	}
}

/*void DFS2(int x,int y,char color)
{
	if(y==1 && c[x][y] == color && color=='W')	state=1;
	if(x==1 && c[x][y] == color && color=='B')	state=2;
	if(y==1 && c[x][y] == 'U' && color=='W' && state!=1 && state!=2 )	state=3;
	if(x==1 && c[x][y] == 'U' && color=='B' && state ==0 )	state=4;

	if( x>0 && y>0 && x<=n && y<=n && c[x][y]==color )
	{
		c[x][y]='0';
		DFS(x-1,y,color);
		DFS(x,y-1,color);
		DFS(x+1,y,color);
		DFS(x,y+1,color);
		c[x][y]='0';
	}
}*/

int main()
{
	while(cin>>n)
	{
		if(n==0)	break;

		ucount = state = 0;

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
				c2[i][j]=c[i][j];
		}
	
		for(int i = 1 ; i <= n && !state ; ++i )
		{
			DFS2(i,1,'W');
		}

		if(!state)
		{
			for(int i = 1 ; i <= n ; ++i )
			{
				for(int j = 1 ; j <= n ; ++j )
					c[i][j]=c2[i][j];
			}
		}

		for(int i = 1 ; i <= n && !state ; ++i )
		{
			DFS(i,1,'W');
		//	DFS2(i,n,'W');
		}

		if(!state)
		{
			for(int i = 1 ; i <= n ; ++i )
			{
				for(int j = 1 ; j <= n ; ++j )
					c[i][j]=c2[i][j];
			}
		}

		for(int i = 1 ; i <= n && !state ; ++i )
		{
			DFS2(1,i,'B');
		}

		if(!state)
		{
			for(int i = 1 ; i <= n ; ++i )
			{
				for(int j = 1 ; j <= n ; ++j )
					c[i][j]=c2[i][j];
			}
		}

		for(int i = 1 ; i <= n && !state ; ++i )
		{
			DFS(1,i,'B');
			//DFS2(n,i,'B');
		}
		
		switch(state)
		{
		case 1:
			cout<<"White has a winning path."<<endl;
			break;
		case 2:
			cout<<"Black has a winning path."<<endl;
			break;
		case 3:
			cout<<"White can win in one move."<<endl;
			break;
		case 4:
			cout<<"Black can win in one move."<<endl;
			break;
		case 0:
			cout<<"There is no winning path."<<endl;
			break;
		}
		//cout<<state;

		/*for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				cout<<c[i][j];
			}cout<<endl;
		}*/
	}
}