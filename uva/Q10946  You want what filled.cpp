#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node
{
public:
	int num;
	char alpha;
};


char c[100][100]={},hole;
int m,n,hcount;

void DFS(int x,int y)
{
	if( x>0 && y>0 && x<=n && y<=m && c[x][y]==hole)
	{
		++hcount;
		c[x][y] = '.';
		DFS(x-1,y);
		DFS(x+1,y);
		DFS(x,y+1);
		DFS(x,y-1);
	}
}

bool cmp(node a,node b)
{
	if(a.num==b.num)	return a.alpha<b.alpha;

	else	return a.num>b.num;
}

int main()
{
	node tmp;
	int casenum=1;
	

	while(cin>>n>>m)
	{
		if(n==0 && m==0)	break;

		vector<node> v;

		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= m ; ++j)
			{
				cin>>c[i][j];
			}
		}

		for(int i = 1 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= m ; ++j)
			{
				if(c[i][j]!='.')
				{
					hcount=0;
					hole = c[i][j];
					DFS(i,j);
					tmp.num = hcount ;
					tmp.alpha = hole;
					v.push_back(tmp);
				}
			}
		}

		sort(v.begin(),v.end(),cmp);
		
		cout<<"Problem "<<casenum++<<':'<<endl;

		for(int i = 0 ; i < v.size() ; ++i )
		{
			cout<<v[i].alpha<<' '<<v[i].num<<endl;
		}
		
	}
}