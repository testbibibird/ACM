#include<iostream>

using namespace std;

class node
{
public:
	int strength;
	int weight;
};

class dp
{
public:
	int num;
	int w;
	dp():num(0),w(0){}
};

int main()
{
	int n ;
	node arr[1000];
	dp rs[1000];

	while(cin>>n && n!=0)
	{
		memset(rs,0,sizeof(rs));

		for(int i = 0 ; i < n ; ++i )
		{
			cin>>arr[i].strength>>arr[i].weight;
		}

		for(int i = 0 ; i < n ; ++i )
		{
			rs[i].num = rs[i].w = 0;
		}

		for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j <= i ; ++j )
			{
				if( arr[i].strength >= rs[j].w )	
				{
					rs[j]
				}
			}
		}
	}
}