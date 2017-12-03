#include<iostream>


using namespace std;

int arr[30001],arr2[30001],group,n,m;

void uni(int x,int y)
{

	if(arr[x]==arr[y])	return;

	group--;

	int big = max(arr[x],arr[y]);
	int small = min(arr[x],arr[y]);

	for(int i = 1 ; i <= n ; ++i )
	{
		if(arr[i] == small)
		{
			arr[i]=big;
			arr2[big]++;
			arr2[small]--;
					
		}
	}

}

int main()
{
	int num,a,b,ma;

	cin>>num;

	while(num--)
	{
		cin>>n>>m;

		group=n,ma=0;

		for(int i = 1 ; i <= n ; ++i)
		{
			arr[i]=i;
			arr2[i]=1;
		}

		for(int i = 0 ; i < m ; ++i)
		{
			cin>>a>>b;

			uni(a,b);
		}

		for(int i = 1 ; i <= n ; ++i )
			if(ma<arr2[i])	ma=arr2[i];
			

		cout<<ma<<endl;
	}
}