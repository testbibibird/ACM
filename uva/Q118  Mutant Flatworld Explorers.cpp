#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	int x,y,state=0,boundx,boundy;
	bool** judge,key;
	string a;
	char dir;

	cin>>x>>y;

	boundx=x;
	boundy=y;

	judge = new bool*[x+1];

	for(int i = 0 ; i <= x ; ++i )
	{
		judge[i] = new bool [y+1];
	}

	for(int i = 0 ; i <= x ; ++i )
	{
		for(int j = 0 ; j <= y ; ++j )
		{
			judge[i][j]=true;
		}
	}

	while(cin>>x>>y>>dir)          //state 0 n 1 e 2 s 3 w
	{
		key = false;

		cin>>a;

		if(dir=='N')	state=0;
		if(dir=='E')	state=1;
		if(dir=='S')	state=2;
		if(dir=='W')	state=3;

		for(int i = 0 ; i < a.size() && !key ; ++i )
		{
			if(a[i]=='R')	state=(state+1)%4;
			if(a[i]=='L')	
			{
				if(state==0)	state=3;
	
				else	state-=1;
			}

			if( a[i]=='F' )
			{
				if( state==0 )
				{
					if( y==boundy && judge[x][y] )
					{
						judge[x][y]=false;
						key=true;
					}
					else if( y==boundy && !judge[x][y] )
					{

					}
					else if( y != boundy )
					{
						y+=1;
					}
					
				}
				else	if(state==1)
				{
					if( x==boundx && judge[x][y])
					{
						judge[x][y]=false;
						key=true;
					}
					else if( x==boundx && !judge[x][y] )
					{

					}
					else if(x != boundx )
					{
						x+=1;
					}
				}
				else	if(state==2)
				{
					if( y==0 && judge[x][y] )
					{
						judge[x][y] = false;
						key = true;
					}
					else if( y==0 && !judge[x][y] )
					{

					}
					else if( y!=0 )
					{
						y-=1;
					}
				}
				else	if(state==3)
				{
					if( x==0 && judge[x][y] )
					{
						judge[x][y] = false;
						key = true;
					}
					else if( x==0 && !judge[x][y] )
					{

					}
					else if( x!=0 )
					{
						x-=1;
					}
				}
				
			}

		/*	if( x<=0 || y<=0 || x>boundx || y>boundy)
			{
				if(state==0)
				{
					judge[x][y-1]=false;
				}
				else	if(state==1)
				{
					judge[x-1][y]=false;

				}
				else	if(state==2)
				{
					judge[x][y+1]=false;
				}
				else	if(state==3)
				{
					judge[x+1][y]=false;
				}

				
			}*/
		}

		cout<<x<<" "<<y<<" ";

		if(state==0)
		{
			cout<<"N";
		}
		else	if(state==1)
		{
			cout<<"E";

		}
		else	if(state==2)
		{
			cout<<"S";
		}
		else	if(state==3)
		{
			cout<<"W";
		}

		if(key)	cout<<" LOST";

		cout<<endl;
	}


}