#include<iostream>
#include<algorithm>

using namespace std;

class node
{
public:
	int x,y;
};

node arr[513],stk[513];


int cross(const node &o,const node &a,const node &b)
{
	return ( a.x-o.x )*( b.y-o.y ) - ( a.y-o.y )*( b.x-o.x );
}

int len(const node &a ,const node &b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool cmp(const node &a,const node &b)
{
	int c = cross(stk[0],a,b) ;

	return (c > 0)|| ( (c==0) && len(stk[0],a) < len(stk[0],b) );
}

int main()
{
	int k,n,index;
	

	cin>>k;
	cout<<k<<endl;

	while(k--)
	{
		cin>>n;

		if(n==-1)
		{
			cout<<-1<<endl;
			cin>>n;
		}

		for(int i = 0 ; i < n ; ++i )
		{
			cin>>arr[i].x>>arr[i].y;
		}

		stk[0] = arr[0];
		for(int i = 1 ; i < n ; ++i )
		{
			if(stk[0].y > arr[i].y || (stk[0].y == arr[i].y && stk[0].x > arr[i].x))
			{
				stk[0] = arr[i];
				swap(arr[i],arr[0]);
			}
		}
		
//		for(int i = 0 ; i < n ; ++i )
//		cout<<arr[i].x<<' '<<arr[i].y<<endl;
		arr[n-1] = stk[0];
		sort(arr+1,arr+n-1,cmp);


		index = 1;

		for(int i = 1 ; i < n ; ++i )
		{

			while( index >= 2 && cross(stk[index-2],stk[index-1],arr[i]) <= 0 )
				--index;

			stk[index++] = arr[i];		
		}

		cout<<index<<endl;
		for(int i = 0 ; i < index ; ++i )
		{
			cout<<stk[i].x<<' '<<stk[i].y<<endl;
		}
	}
}
