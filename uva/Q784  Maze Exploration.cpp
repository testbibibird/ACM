#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string>	v;
bool used[1000][1000]={};
int mmax;

void DFS(int x,int y)
{
	if(x>=0 && y>=0 && x < v.size()  && y < mmax )
	{
		if( v[x][y]==' ' && !used[x][y])
		{
		//	cout<<x<<' '<<y<<endl;

			/*if(y>0 )
			{
				if( v[x][y-1]=='X')	v[x][y]='#';
			}
			if(y < mmax-1 )
			{
				if (v[x][y+1]=='X')	v[x][y]='#';
			}
			if(x < v.size()-1 )
			{	
				//if( y < v[x+1].size() )
					if (  v[x+1][y]=='X')	v[x][y]='#';
			}	
			if(x > 0 )
			{	
				//if( y < v[x-1].size() )
					if( v[x-1][y]=='X')	v[x][y] = '#';
			}*/
			
			used[x][y]=true;
			v[x][y]='#';

			DFS(x+1,y);
			DFS(x-1,y);
			DFS(x,y+1);
			DFS(x,y-1);
		}
	}
}

int main()
{
	int n;
	string a,sep;

	cin>>n;

	getline(cin,a);

	while(n--)
	{
		mmax=0;

		while(getline(cin,a))
		{
			if(a[0]=='_')
			{
				sep=a;	break;
			}
			if(mmax<a.size())	mmax = a.size();

			v.push_back(a);
		}

		//v[0].resize(v[1].size()+2,' ');
		//v.back().resize(v[v.size()-2].size()+2,' ');

		mmax+=2;

		for(int i = 0 ; i < v.size() ; ++i )	v[i].resize(mmax,' ');

		memset(used,0,1000*1000);

		for(int i = 0 ; i < v.size() ; ++i )
		{
			for(int j = 0 ; j < v[i].size() ; ++j )
			{
				if(v[i][j]=='*')	
				{
					v[i][j]=' ';
					DFS(i,j);
				}
			}
		}

		for(int i = 0 ; i < v.size() ; ++i )
		{
			//cout<<v[i].find_last_not_of(' ')<<endl;
			v[i].resize(v[i].find_last_not_of(' ')+1);//<<endl;
		}

		for(int i = 0 ; i < v.size() ; ++i )
		{
			cout<<(v[i])<<endl;
			/*for(int j = 0 ; j < v[i].size() ; ++j )
				cout<<static_cast<int>( v[i][j]);
			cout<<endl;*/
		}
		cout<<sep<<endl;

		v.clear();
	}
}