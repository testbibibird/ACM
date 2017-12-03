#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class node
{
public:
	int x;
	int y;
};

bool cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	int num,n;
	node arr[100000];
	long long sum;

	cin>>num;

	while(num--)
	{
		cin>>n;

		for(int i = 0 ; i < n ; ++i )	cin>>arr[i].x>>arr[i].y;
	
		sort(arr,arr+n,cmp);

		sum=0;

	//	for(int i = 0 ; i < n ; ++i )	cout<<arr[i].x<<' '<<arr[i].y<<endl;

		
		for(int i = 0 ; i < n ; i+=2 )
		{
			sum += abs(arr[i].y - arr[i+1].y);
		}
		//cout<<sum<<endl;

		sum += 2*( arr[n-1].x - arr[0].x );

		cout<<sum<<endl;
	
	}

	


}