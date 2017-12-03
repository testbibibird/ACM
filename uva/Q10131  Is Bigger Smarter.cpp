#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

class node
{
public:
	int w,s,num;
};

bool cmp( node a, node b ) {
	if(a.s > b.s)	return true;
	else if(a.s==b.s)	return a.w<b.w;
	return false;
  }

bool cmp2( node a, node b ) {
	return a.w < b.w;
  }

int main()
{
	list<int> rs;
	vector<node> arr,v;
	//vector<int> lis;
	int lis[1000]={},prev[1000]={};
	vector<node>::iterator it;
	node tmp;
	int count=1,mmax,postmp;

	while(cin>>tmp.w>>tmp.s)
	{
		tmp.num=count++;

		arr.push_back(tmp);
	}

	sort(arr.begin() , arr.end() , cmp);

//	for(int i=0 ;  i<arr.size();++i)	cout<<arr[i].w<<" "<<arr[i].s<<endl;

	for(int i = 0 ; i < arr.size() ; ++i )	
	{
		lis[i]=1;
		prev[i]=-1;
	}
	for(int i = 0 ; i < arr.size() ; ++i )
	{
		for(int j = i-1 ; j >= 0 ; --j )
		{
			if(arr[i].w > arr[j].w && arr[i].s!=arr[j].s )	
			{
				if( lis[i] < lis[j]+1 )	prev[i] = j ;
				
				lis[i] = max(lis[i],lis[j]+1);
			}

			
		}
	}

/*	v.push_back(arr[0]);
	lis.push_back(1);

	for(size_t i = 1 ; i < arr.size() ; ++i)
	{
		
		if( arr[i].w > v.back().w )
		{
			v.push_back( arr[i] );
			lis.push_back( v.size() );
		}
		else
		{
			it = lower_bound(v.begin() , v.end() , arr[i] , cmp2 );
			lis.push_back( it-v.begin() + 1 );
			*it = arr[i];
		}
	}*/
	mmax=0;

	for(int i = 0 ; i < arr.size() ; ++i )
	{
		if(mmax < lis[i])
		{
			mmax = lis[i];
			postmp = i;
		}
	}

	cout<<mmax<<endl;

	for(int i = 0 ; i < mmax && postmp!=-1 ; ++i )
	{
		rs.push_front( arr[postmp].num );
		postmp = prev[postmp];
	}

	/*for(int i = lis.size()-1 ,j=v.size() ; i >= 0  ; --i)
	{
		if( lis[i] == j )
		{
			rs.push_front( arr[i].num );
			--j;
		}
	}

	cout<<v.size()<<endl;*/

	for(list<int>::iterator its=rs.begin() ; its != rs.end(); its++)
	{
		cout<<*its<<endl;
	}
	
}