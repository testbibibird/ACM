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
	pair<double,double> one;
	pair<double,double> two;
	pair<double,double> three;
};



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
		if(g[i].kind=='t')
		{
			cin>>g[i].one.first>>g[i].one.second>>g[i].two.first>>g[i].two.second>>g[i].three.first>>g[i].three.second;
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

			if(g[j].kind=='t')
			{
				pair<double,double> vectorab;
				vectorab.first=g[j].two.first-g[j].one.first; vectorab.second=g[j].two.second-g[j].one.second;
				pair<double,double> vectorbc;
				vectorbc.first=g[j].three.first-g[j].two.first; vectorbc.second=g[j].three.second-g[j].two.second;
				pair<double,double> vectorcd;
				vectorcd.first=x-g[j].three.first; vectorcd.second=y-g[j].three.second;
				pair<double,double> vectorad;
				vectorad.first=x-g[j].one.first; vectorad.second=y-g[j].one.second;
				pair<double,double> vectorca;
				vectorca.first=g[j].one.first-g[j].three.first; vectorca.second=g[j].one.second-g[j].three.second;
				pair<double,double> vectorbd;
				vectorbd.first=x-g[j].two.first; vectorbd.second=y-g[j].two.second;



				if( (vectorab.first*vectorbd.second-vectorab.second*vectorbd.first>0 && vectorbc.first*vectorcd.second-vectorbc.second*vectorcd.first>0 && vectorca.first*vectorad.second-vectorca.second*vectorad.first>0 )||(vectorab.first*vectorbd.second-vectorab.second*vectorbd.first<0 && vectorbc.first*vectorcd.second-vectorbc.second*vectorcd.first<0 && vectorca.first*vectorad.second-vectorca.second*vectorad.first<0))
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

