#include<iostream>
#include<string>
#include<vector>

using namespace std;

class edge
{
public:
	int u,v,w;
};

int main()
{
	int n,m,si,ki,ni,d[200]={};
	vector<edge> e;
	int infinite = 1000000000;
	string oi;
	edge tmp;
	bool neg;

	while(cin>>n)
	{
		if(n==0)	break;
		
		neg = false;
		if(!e.empty()) e.clear();

		cin>>m;

		for(int i = 0 ; i < n ; ++i )
		{
			d[i] = infinite;
		}
		d[0] = 0;

		for(int i = 0 ; i < m ; ++i )
		{
			cin>>si>>ni>>oi>>ki;

			if(oi=="gt")
			{
				tmp.u = si+ni;
				tmp.v = si-1;
				tmp.w = -ki-1;				
			}
			else
			{
				tmp.u = si-1;
				tmp.v = si+ni;
				tmp.w = ki-1;
			}
			e.push_back(tmp);
		}
		
		for(int i = 0 ; i < n  ; ++i )
		{
			for(int j = 0 ; j < e.size() ; ++j )
			{
				if( d[e[j].v] > d[e[j].u] + e[j].w )
					d[e[j].v] = d[e[j].u] + e[j].w;
			}
		}

		for(int j = 0 ; j < e.size() ; ++j )
		{
			if( d[e[j].v] > d[e[j].u] + e[j].w )
			{
				neg = true;
				break;			
			}
		}


		if(neg)	cout<<"successful conspiracy"<<endl;
		else cout<<"lamentable kingdom"<<endl;
	}
}