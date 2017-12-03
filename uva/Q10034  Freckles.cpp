//UVA 10034

#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

class edge{
public:
	int u,v;

	double w;
};


double dis(pair<double,double> a,pair<double,double> b)
{
	return  (a.first - b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second) ;
}

bool cmp(const edge &a ,const edge &b)
{
	return a.w < b.w;
}

void make_set(int& p,int i )
{
	p = i ;
}

int find_set(int *p ,int i)
{
	if(p[i] != i )
		p[i] = find_set(p,p[i]);
	return p[i];
}

void union_set(int* p,int i,int j)
{
	p[find_set(p,i)] = p[j];
}



int main()
{
	int case_num,n,e_num,mst_num;
	double mst_w;
	pair<double,double> arr[100];
	int disjoint_set[100]={};
	edge mst[99];
	edge e[10000];
	bool flag = false;
	cin>>case_num;

	while(case_num--)
	{
		if(flag)	cout<<endl;

		cin>>n;

		e_num = 0;
		mst_num = 0;
		mst_w = 0;

		for(int i = 0 ; i < n ; ++i )	//make-set
		{
			make_set(disjoint_set[i],i);
		}

		for(int i = 0 ; i < n ; ++i )  //initial
		{
			cin>>arr[i].first>>arr[i].second;
		}

		for(int i = 0 ; i < n ; ++i )
		{
			for(int j = i+1 ; j < n ; ++j )
			{
				e[e_num].u = i;
				e[e_num].v = j;
				e[e_num++].w = dis(arr[i],arr[j]);
			}
		}

		sort(e,e+e_num,cmp);

		//do kruskal;
		

		for(int i = 0 ; mst_num < n-1 && i < e_num ; ++i )
		{
			
			if( find_set(disjoint_set,e[i].u) != find_set(disjoint_set,e[i].v) )  //check cycle
			{

				mst[mst_num++] = e[i]; //take the edge
				mst_w += sqrt(e[i].w); //sum the MST w
				union_set(disjoint_set,e[i].u,e[i].v);//union two edge make them in same set
//				
			}
		}
		
		cout<<fixed<<setprecision(2)<<mst_w<<endl;
		flag = true;
	}
}
