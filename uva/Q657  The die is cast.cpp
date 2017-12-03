#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


char c[100][100]={};
int w,h,num;

void DFSX(int x,int y)
{
	if(x>=0 && y>=0 && x<h && y<w )
	{
		if(c[x][y]=='X')
		{
			c[x][y]='*';

			DFSX(x,y+1);
			DFSX(x+1,y);
			DFSX(x-1,y);
			DFSX(x,y-1);
		}
	}
}
void DFS(int x,int y)
{
	if(x>=0 && y>=0 && x<h && y<w )
	{
		if(c[x][y]!='.')
		{
			//if(c[x][y]=='X'&& c[x+1][y]!='X' && c[x-1][y]!='X' && c[x][y+1]!='X' && c[x][y-1]!='X')	num++;
			
			if(c[x][y]=='X')	
			{
				DFSX(x,y);
				++num;
			}

		//	if(xcount==1&&c[x][y]=='X')	num++;

			c[x][y]='.';

			DFS(x,y+1);
			DFS(x+1,y);
			DFS(x-1,y);
			DFS(x,y-1);

			//if(c[x][y]=='X')	--xcount
		}
	}
}


int main()
{
	int count=0;

	while(cin>>w>>h)
	{
		if(w==0&&h==0)	break;
		
		vector<int> rs;
		//memset(c,0,50*50*2);

		cin.getline(c[0],51);

		for(int i = 0 ; i < h ; ++i )
		{
			cin.getline(c[i],52);
		}
		//cout<<endl;
		/*for(int i = 0 ; i < h ; ++i )
		{
			cout<<c[i]<<endl;//cin.getline(c[i],50);
		}*/

		for(int i = 0 ; i < h ; ++i )
		{
			for(int j = 0 ; j < w ; ++j , num=0 )
			{
				if(c[i][j]!='.')
				{
					DFS(i,j);
					if(num>0&& num < 7)	rs.push_back(num);
				}
			}
		}
		sort(rs.begin(),rs.end());

		cout<<"Throw "<<++count<<endl;

		if(!rs.empty() )
		cout<<rs[0];
		for(int i = 1 ; i < rs.size() ; ++i )
		{
			cout<<' '<<rs[i];
		}
		//if(!rs.empty())	
		cout<<endl;
		cout<<endl;

		
	}
}