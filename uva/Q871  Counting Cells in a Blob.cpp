#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> v;
int ucount;

void DFS(int x,int y)
{
	if( x>=0 && y>=0 && x< v.size() && y < v[x].size())
	{
		if(v[x][y]=='1')
		{
			++ucount;
			v[x][y]='0';

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
}

int main()
{
	int n ,rs,casenum=0;
	string a;

	cin>>n;

	getline(cin,a);
	getline(cin,a);

	while(n--)
	{
		while(getline(cin,a))
		{
			if(a=="")	break;

			v.push_back(a);
		}

		if(casenum)	cout<<endl;

		rs=0;
		
		for(int i = 0 ; i < v.size() ; ++i )
		{
			for(int j = 0 ; j < v[i].size() ; ++j )
			{
				if(v[i][j]=='1')
				{
					ucount=0;
					DFS(i,j);
					if( rs < ucount )	rs= ucount;
				}
			}
		}

		cout<<rs<<endl;
		
		++casenum;

		v.clear();
	}
}