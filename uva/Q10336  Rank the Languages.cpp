#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

char** c;
int m,n;
class node
{
public:
	char a;
	int lnum;
};

bool cmp(node a,node b)
{
	if(a.lnum==b.lnum)	return a.a<b.a;

	return a.lnum>b.lnum;
}

void DFS(int x,int y,char t)
{
	if( x > 0 && y > 0 && x <= m && y <= n )
	{
		c[x][y] = '0';
		//cout<<t<<endl;;
		if( c[x-1][y] == t)	DFS(x-1,y,t);
		if( c[x][y-1] == t) DFS(x,y-1,t);
		if( c[x+1][y] == t)	DFS(x+1,y,t);
		if( c[x][y+1] == t)	DFS(x,y+1,t);
	}
}

int main()
{
	map<const char,int> alpha;
	alpha['a'] = 0 ;
	alpha['b'] = 1 ;
	alpha['c'] = 2 ;
	alpha['d'] = 3 ;
	alpha['e'] = 4 ;
	alpha['f'] = 5 ;
	alpha['g'] = 6 ;
	alpha['h'] = 7 ;
	alpha['i'] = 8 ;
	alpha['j'] = 9 ;
	alpha['k'] = 10 ;
	alpha['l'] = 11 ;
	alpha['m'] = 12 ;
	alpha['n'] = 13 ;
	alpha['o'] = 14 ;
	alpha['p'] = 15 ;
	alpha['q'] = 16 ;
	alpha['r'] = 17 ;
	alpha['s'] = 18 ;
	alpha['t'] = 19 ;
	alpha['u'] = 20 ;
	alpha['v'] = 21 ;
	alpha['w'] = 22 ;
	alpha['x'] = 23 ;
	alpha['y'] = 24 ;
	alpha['z'] = 25 ;
	
	int num,num2=0,count;
	char tmp;
	node tmp1[26];

	for(int i = 0 ; i < 26 ; ++i )
	{
		tmp1[i].a = 'a'+i;
		tmp1[i].lnum = 0 ;
	}


	cin>>num;

	while(num2++<num)
	{	
		vector<node> v(tmp1,tmp1+26);

		cin>>m>>n;
		count=0;
		
		c = new char* [m+2];

		for(int i = 0 ; i < m+2 ; ++i )
		{
			c[i] = new char[n+2];
		}

		//memset(c,0,n*m);

		for(int i = 1 ; i <= m ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				cin>>c[i][j];
			}
		}

		for( int i = 1 ; i <= m ; ++i )
		{
			for( int j = 1; j <= n ; ++j )
			{
				if(c[i][j]!='0')	
				{
				//	cout<<i<<' '<<j<<' '<<c[i][j]<<endl;
					tmp = c[i][j];
					c[i][j]='0';
					v[ alpha[ tmp ] ].lnum++;
					DFS(i,j,tmp);
				}
			}
		}

		sort(v.begin(),v.end(),cmp);

		cout<<"World #"<<num2<<endl;

		for(int i = 0 ; i < 26 && v[i].lnum!=0 ; ++i )
		{
			cout<<v[i].a<<": "<<v[i].lnum<<endl;
		}

		for(int i = 0 ; i < m+2 ; ++i )
		{
			delete [] c[i];
		}
		delete [] c;
	}
}
