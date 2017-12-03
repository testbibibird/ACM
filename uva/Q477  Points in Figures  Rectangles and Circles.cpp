#include<iostream>
#include<cmath>

using namespace std;

bool judge(int*,int ,int );

struct graph{
	//int num;
	char kind;
	pair<double,double> l;
	pair<double,double> r;
	double radius;
	double x;
	double y;
};

/*struct cir{
	double radius;
	double x;
	double y;
};*/

int main()
{
	graph g[11];
	int i=0;
	double x,y;
	int count=1;

	while(cin>>g[i].kind)
	{
		if(g[i].kind=='*')	break;

		if(g[i].kind=='r')   
		{
			cin>>g[i].l.first>>g[i].l.second>>g[i].r.first>>g[i].r.second;
		}
		if(g[i].kind=='c')
		{
			cin>>g[i].x>>g[i].y>>g[i].radius;
		}

		++i;
	}

	while(cin>>x>>y)
	{
		int tok=0;

		if( x==9999.9 && y==9999.9)	break;

		for(int j=0;j<i;++j)
		{
			if(g[j].kind=='r')
			{
				if(g[j].l.first<x && x<g[j].r.first && g[j].l.second>y && y>g[j].r.second)
				{
					cout<<"Point "<<count<<" is contained in figure "<<j+1<<endl;
					++tok;
				}
				
			}
			if(g[j].kind=='c')
			{
				if((x-g[j].x)*(x-g[j].x)+(y-g[j].y)*(y-g[j].y) < g[j].radius*g[j].radius)
				{
					cout<<"Point "<<count<<" is contained in figure "<<j+1<<endl;
					++tok;
				}
				
			}
		}

		if(tok==0)
		{
			cout<<"Point "<<count<<" is not contained in any figure"<<endl;
		}

		count++;
	}

}

