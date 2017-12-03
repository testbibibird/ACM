#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string>	v;
bool used[1000][1000]={};
//int mmax;
char c;

void DFS(int x,int y)
{
	if(x>=0 && y>=0 && x < v.size()  && y < v[x].size() )
	{
		if( v[x][y]==' ' && !used[x][y])
		{
		
			used[x][y]=true;
			v[x][y]=c;

			DFS(x+1,y);
			DFS(x-1,y);
			DFS(x,y+1);
			DFS(x,y-1);
		}
	}
}

int main()
{
	string a,sep;
	bool key;
	char zone;

	//cin>>n;

	//getline(cin,a);

	while(getline(cin,a))
	{
	//	mmax=0;
		key = false;

		if(a[0]=='_')
		{
			sep=a;
			cout<<sep<<endl;
			continue;
		}

	//	if(mmax<a.size())	mmax = a.size();

		v.push_back(a);

		while(getline(cin,a))
		{
			if(a[0]=='_')
			{
				sep=a;	break;
			}
	//		if(mmax<a.size())	mmax = a.size();

			v.push_back(a);
		}

		zone = ' ';

		for(int i = 0 ; i < v.size() && zone == ' ' ; ++i )
		{
			for(int j = 0 ; j < v[i].size() && zone == ' ' ; ++j )
			{
				if(v[i][j] != ' ' )	zone = v[i][j];
			}
		}
		//zone = v[1][v[1].find_first_not_of(' ')];
		//cout<<zone;

		//v[0].resize(v[1].size()+2,' ');
		//v.back().resize(v[v.size()-2].size()+2,' ');

		//mmax+=2;

	//	for(int i = 0 ; i < v.size() ; ++i )	v[i].resize(mmax,' ');

		memset(used,0,1000*1000);

		for(int i = 0 ; i < v.size() ; ++i )
		{
			for(int j = 0 ; j < v[i].size() ; ++j )
			{
				if(v[i][j]!=zone && v[i][j]!=' ' && !used[i][j] )	
				{
				//	cout<<i<<' '<<j<<endl;
					c = v[i][j];
					v[i][j]=' ';
					DFS(i,j);
				}
			}
		}

		/*for(int i = 0 ; i < v.size() ; ++i )
		{
			//cout<<v[i].find_last_not_of(' ')<<endl;
			v[i].resize(v[i].find_last_not_of(' ')+1);//<<endl;
		}*/

		for(int i = 0 ; i < v.size() ; ++i )
		{
			cout<<(v[i])<<endl;
		/*	for(int j = 0 ; j < v[i].size() ; ++j )
				cout<<static_cast<int>( v[i][j]);
			cout<<endl;*/
		}
		cout<<sep<<endl;

		v.clear();
	}
}